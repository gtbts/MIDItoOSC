/*
 ==============================================================================
 
 This file was auto-generated by the Introjucer!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MiditoOscAudioProcessor::MiditoOscAudioProcessor()

{
    addParameter (polyphony = new AudioParameterInt ("polyphony",  "Polyphony", 1, 6, 1));
    addParameter (glide = new AudioParameterFloat ("glide",  "Glide", 0.0f, 1.0f, 0.0f));
    addParameter (mono = new AudioParameterBool ("mono",  "Mono", false));
    addParameter (shift = new AudioParameterBool ("shift",  "Shift", false));
    addParameter (scale = new AudioParameterInt ("scale",  "Scale", 1, 9, 1));
    
    transmitSocket.Connect( IpEndpointName("127.0.0.1", 9000) );
}

MiditoOscAudioProcessor::~MiditoOscAudioProcessor()
{
}

//==============================================================================
const String MiditoOscAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MiditoOscAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool MiditoOscAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool MiditoOscAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double MiditoOscAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MiditoOscAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int MiditoOscAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MiditoOscAudioProcessor::setCurrentProgram (int index)
{
}

const String MiditoOscAudioProcessor::getProgramName (int index)
{
    return String();
}

void MiditoOscAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MiditoOscAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MiditoOscAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void MiditoOscAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    static float cv[8], shiftcv[8];
    static bool _calibMode;
    
    MidiBuffer processedMidi;
    MidiMessage m;
    int time;
    
    char oscBuffer[IP_MTU_SIZE];
    osc::OutboundPacketStream p(oscBuffer, IP_MTU_SIZE);
    
    if (calibMode) // Calibration Mode A440Hz(MIDI number 69)
    {
        p << osc::BeginBundleImmediate
        << osc::BeginMessage( "/fader1" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/fader2" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/fader3" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/fader4" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/fader5" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/fader6" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/fader7" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/fader8" )
        << calibMap[69] << osc::EndMessage
        << osc::BeginMessage( "/gate1" )
        << 1 << osc::EndMessage
        << osc::BeginMessage( "/gate2" )
        << 1 << osc::EndMessage
        << osc::EndBundle;
        
        sendOSCData(p);
        
        _calibMode = true;
        
        return;
        
    } else {
        
        if (_calibMode)
        {
            p << osc::BeginBundleImmediate
            << osc::BeginMessage( "/gate1" )
            << 0 << osc::EndMessage
            << osc::BeginMessage( "/gate2" )
            << 0 << osc::EndMessage
            << osc::EndBundle;
            
            sendOSCData(p);
            
            _calibMode = false;
            
        }
    }
    
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        p.Clear();
        usleep(30);
        
        if (m.isNoteOn())
        {
            if (monoMode) // mono Mode
            {
                uint32_t midiCh = m.getChannel();
                
                if (midiCh == 0 || midiCh > 7)
                {
                    midiCh = 1;
                }
                
                cv[midiCh - 1] = calibMap[m.getNoteNumber()];
                
                switch (midiCh)
                {
                    case 1:
                        p << osc::BeginMessage("/fader1")
                        << cv[0] << osc::EndMessage;
                        break;
                        
                    case 2:
                        p << osc::BeginMessage("/fader2")
                        << cv[1] << osc::EndMessage;
                        break;
                        
                    case 3:
                        p << osc::BeginMessage("/fader3")
                        << cv[2] << osc::EndMessage;
                        break;
                        
                    case 4:
                        p << osc::BeginMessage("/fader4")
                        << cv[3] << osc::EndMessage;
                        break;
                        
                    case 5:
                        p << osc::BeginMessage("/fader5")
                        << cv[4] << osc::EndMessage;
                        break;
                        
                    case 6:
                        p << osc::BeginMessage("/fader6")
                        << cv[5] << osc::EndMessage;
                        break;
                        
                    case 7:
                        p << osc::BeginMessage("/fader7")
                        << cv[6] << osc::EndMessage;
                        break;
                        
                    case 8:
                        p << osc::BeginMessage("/fader8")
                        << cv[7] << osc::EndMessage;
                        break;
                        
                    default:
                        break;
                }
                
                sendOSCData(p);
                
            } else if (shiftMode) { // shift Mode
                
                cv[0] = calibMap[m.getNoteNumber()];
                
                for (int i = 7; i > 0; i--)
                {
                    shiftcv[i] = shiftcv[i-1];
                }
                
                p << osc::BeginBundleImmediate
                << osc::BeginMessage( "/fader1" )
                << cv[0] << osc::EndMessage
                << osc::BeginMessage( "/fader2" )
                << shiftcv[1] << osc::EndMessage
                << osc::BeginMessage( "/fader3" )
                << shiftcv[2] << osc::EndMessage
                << osc::BeginMessage( "/fader4" )
                << shiftcv[3] << osc::EndMessage
                << osc::BeginMessage( "/fader5" )
                << shiftcv[4] << osc::EndMessage
                << osc::BeginMessage( "/fader6" )
                << shiftcv[5] << osc::EndMessage
                << osc::BeginMessage( "/fader7" )
                << shiftcv[6] << osc::EndMessage
                << osc::BeginMessage( "/fader8" )
                << shiftcv[7] << osc::EndMessage
                << osc::BeginMessage( "/gate1" )
                << 1 << osc::EndMessage
                << osc::BeginMessage( "/gate2" )
                << 1 << osc::EndMessage
                << osc::EndBundle;
                
                sendOSCData(p);
                
                shiftcv[0] = cv[0];
                
            } else { // poly Mode
                
                cv[ch] = calibMap[m.getNoteNumber()];
                
                if (currentMaxPoly == 1)
                {
                    cv[1] = cv[0];
                }
                
                p << osc::BeginBundleImmediate
                << osc::BeginMessage( "/fader1" )
                << cv[0] << osc::EndMessage
                << osc::BeginMessage( "/fader2" )
                << cv[1] << osc::EndMessage
                << osc::BeginMessage( "/fader3" )
                << cv[2] << osc::EndMessage
                << osc::BeginMessage( "/fader4" )
                << cv[3] << osc::EndMessage
                << osc::BeginMessage( "/fader5" )
                << cv[4] << osc::EndMessage
                << osc::BeginMessage( "/fader6" )
                << cv[5] << osc::EndMessage
                << osc::BeginMessage( "/fader7" )
                << m.getFloatVelocity() << osc::EndMessage
                << osc::BeginMessage( "/gate1" )
                << 1 << osc::EndMessage
                << osc::BeginMessage( "/gate2" )
                << 1 << osc::EndMessage
                << osc::EndBundle;
                
                sendOSCData(p);
                
                ch++;
                gateCount++;
                
                if (ch >= currentMaxPoly)
                {
                    ch = 0;
                }
                
            }
            
        } else if (m.isNoteOff()) {
            
            if (monoMode)
            {
                switch (m.getChannel())
                {
                    case 1:
                        p << osc::BeginMessage( "/gate1" )
                        << 0 << osc::EndMessage;
                        break;
                        
                    case 2:
                        p << osc::BeginMessage( "/gate2" )
                        << 0 << osc::EndMessage;
                        break;
                        
                    case 3:
                        p << osc::BeginMessage( "/gate3" )
                        << 0 << osc::EndMessage;
                        break;
                        
                    case 4:
                        p << osc::BeginMessage( "/gate4" )
                        << 0 << osc::EndMessage;
                        break;
                        
                    default:
                        break;
                }
                
                sendOSCData(p);
                
            } else if (shiftMode) {
                
                p << osc::BeginBundleImmediate
                << osc::BeginMessage( "/gate1" )
                << 0 << osc::EndMessage
                << osc::BeginMessage( "/gate2" )
                << 0 << osc::EndMessage
                << osc::EndBundle;
                
                sendOSCData(p);
                
            } else {
                
                gateCount --;
                
                if (gateCount <= 0)
                {
                    p << osc::BeginBundleImmediate
                    << osc::BeginMessage( "/gate1" )
                    << 0 << osc::EndMessage
                    << osc::BeginMessage( "/gate2" )
                    << 0 << osc::EndMessage
                    << osc::EndBundle;
                    
                    sendOSCData(p);
                    
                    gateCount = 0;
                }
                
                ch--;
                
                if (ch == -1)
                {
                    ch = 0;
                }
                
            }
            
        } else if (m.isControllerOfType(1)) { // Modulation Wheel
            
            float modulation = m.getControllerValue();
            
            if (!monoMode && !shiftMode)
            {
                p << osc::BeginMessage("/fader8")
                << (modulation / 127) << osc::EndMessage;
                
                sendOSCData(p);
            }
            
        }
        
        processedMidi.addEvent (m, time);
    }
    
    midiMessages.swapWith (processedMidi);
    
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = 0;
    }
}

//==============================================================================
bool MiditoOscAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MiditoOscAudioProcessor::createEditor()
{
    return new MiditoOscAudioProcessorEditor (*this);
}

//==============================================================================
void MiditoOscAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    MemoryOutputStream stream (destData, true);
    
    stream.writeInt (*polyphony);
    stream.writeFloat (*glide);
    stream.writeBool (*mono);
    stream.writeBool (*shift);
    stream.writeInt (*scale);
}

void MiditoOscAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    MemoryInputStream stream (data, static_cast<size_t> (sizeInBytes), false);
    
    polyphony->setValueNotifyingHost (stream.readInt());
    glide->setValueNotifyingHost (stream.readFloat());
    mono->setValueNotifyingHost (stream.readBool());
    shift->setValueNotifyingHost (stream.readBool());
    scale->setValueNotifyingHost (stream.readInt());
}

//==============================================================================
void MiditoOscAudioProcessor::setOSCConnection (const juce::String address, const uint16_t port)
{
    transmitSocket.Connect( IpEndpointName(address.getCharPointer(), port) );
}

void MiditoOscAudioProcessor::sendOSCData (const osc::OutboundPacketStream p)
{
    transmitSocket.Send( p.Data(), p.Size() );
}

void MiditoOscAudioProcessor::sendGlideValue (const float currentGlide)
{
    static float _currentGlide = 0;
    
    if (_currentGlide != currentGlide)
    {
        char oscBuffer[128];
        osc::OutboundPacketStream p(oscBuffer, 128);
        p << osc::BeginMessage( "/ctrl4" )
        << (float)currentGlide << osc::EndMessage;
        
        sendOSCData(p);
        
        _currentGlide = currentGlide;
    }
}

void MiditoOscAudioProcessor::sendScaleValue (const uint8_t currentScale)
{
    float scaleValue;
    
    switch (currentScale)
    {
        case Major:
            scaleValue = 0.25;
            break;
        case M7:
            scaleValue = 0.375;
            break;
        case Min7:
            scaleValue = 0.5;
            break;
        case Dorian:
            scaleValue = 0.625;
            break;
        case Minor:
            scaleValue = 0.75;
            break;
        case fifth:
            scaleValue = 0.875;
            break;
        case Whole:
            scaleValue = 1;
            break;
            
        default:
            scaleValue = 0;
            break;
    }
    
    char oscBuffer[128];
    osc::OutboundPacketStream p(oscBuffer, 128);
    p << osc::BeginMessage( "/ctrl2" )
    << (float)scaleValue << osc::EndMessage;
    sendOSCData(p);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MiditoOscAudioProcessor();
}