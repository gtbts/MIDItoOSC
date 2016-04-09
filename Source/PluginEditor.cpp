/*
 ==============================================================================
 
 This file was auto-generated by the Introjucer!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MiditoOscAudioProcessorEditor::MiditoOscAudioProcessorEditor (MiditoOscAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    //GUI ==========================================================================
    
    addAndMakeVisible (remoteAddressText = new TextEditor ("IP"));
    remoteAddressText->setMultiLine (false);
    remoteAddressText->setReturnKeyStartsNewLine (false);
    remoteAddressText->setReadOnly (false);
    remoteAddressText->setScrollbarsShown (false);
    remoteAddressText->setCaretVisible (true);
    remoteAddressText->setPopupMenuEnabled (true);
    remoteAddressText->setText (TRANS("127.0.0.1"));
    remoteAddressText->addListener(this);
    
    addAndMakeVisible (remotePortText = new TextEditor ("port"));
    remotePortText->setMultiLine (false);
    remotePortText->setReturnKeyStartsNewLine (false);
    remotePortText->setReadOnly (false);
    remotePortText->setScrollbarsShown (true);
    remotePortText->setCaretVisible (true);
    remotePortText->setPopupMenuEnabled (true);
    remotePortText->setText (TRANS("9000"));
    remotePortText->addListener(this);
    
    addAndMakeVisible (maxPoly = new Slider ("Polyphony"));
    maxPoly->setRange (1, 6, 1);
    maxPoly->setSliderStyle (Slider::LinearHorizontal);
    maxPoly->setTextBoxStyle (Slider::TextBoxLeft, false, 30, 14);
    maxPoly->setColour (Slider::thumbColourId, Colour (0xff909eb4));
    maxPoly->addListener (this);
    
    addAndMakeVisible (glide = new Slider ("Glide"));
    glide->setRange (0, 1, 0.01);
    glide->setSliderStyle (Slider::LinearHorizontal);
    glide->setTextBoxStyle (Slider::TextBoxLeft, false, 30, 14);
    glide->setColour (Slider::thumbColourId, Colour (0xff909eb4));
    glide->addListener (this);
    
    addAndMakeVisible (labelPolyphony = new Label (String(), TRANS("Polyphony\n")));
    labelPolyphony->setFont (Font ("Futura", 14.00f, Font::plain));
    labelPolyphony->setJustificationType (Justification::centredLeft);
    labelPolyphony->setEditable (false, false, false);
    labelPolyphony->setColour (Label::textColourId, Colour (0xff363636));
    labelPolyphony->setColour (TextEditor::textColourId, Colours::black);
    labelPolyphony->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (labelGlide = new Label (String(), TRANS("Glide")));
    labelGlide->setFont (Font ("Futura", 14.00f, Font::plain));
    labelGlide->setJustificationType (Justification::centredLeft);
    labelGlide->setEditable (false, false, false);
    labelGlide->setColour (Label::textColourId, Colour (0xff363636));
    labelGlide->setColour (TextEditor::textColourId, Colours::black);
    labelGlide->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (scaleSelect = new ComboBox ("scale"));
    scaleSelect->setEditableText (false);
    scaleSelect->setJustificationType (Justification::centred);
    scaleSelect->setTextWhenNothingSelected (TRANS("Chromatic"));
    scaleSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    scaleSelect->addItem (TRANS("Chromatic"), 1);
    scaleSelect->addItem (TRANS("Major"), 2);
    scaleSelect->addItem (TRANS("M7"), 3);
    scaleSelect->addItem (TRANS("Min7"), 4);
    scaleSelect->addItem (TRANS("Dorian"), 5);
    scaleSelect->addItem (TRANS("Minor"), 6);
    scaleSelect->addItem (TRANS("5th"), 7);
    scaleSelect->addItem (TRANS("Whole"), 8);
    scaleSelect->addItem (TRANS("Calibration"), 9);
    scaleSelect->addListener (this);
    
    addAndMakeVisible (labelScale = new Label (String(), TRANS("Scale\n")));
    labelScale->setFont (Font ("Futura", 14.00f, Font::plain));
    labelScale->setJustificationType (Justification::centredLeft);
    labelScale->setEditable (false, false, false);
    labelScale->setColour (Label::textColourId, Colour (0xff363636));
    labelScale->setColour (TextEditor::textColourId, Colours::black);
    labelScale->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (monoButton = new TextButton ("monoFlag"));
    monoButton->setButtonText (TRANS("Mono"));
    monoButton->addListener (this);
    monoButton->setColour (TextButton::buttonColourId, Colour (0xffc4c4c4));
    monoButton->setColour (TextButton::buttonOnColourId, Colour (0xff00CC88));
    
    addAndMakeVisible (shiftButton = new TextButton ("shiftFlag"));
    shiftButton->setButtonText (TRANS("Shift"));
    shiftButton->addListener (this);
    shiftButton->setColour (TextButton::buttonColourId, Colour (0xffc4c4c4));
    shiftButton->setColour (TextButton::buttonOnColourId, Colour (0xff00CC88));
    
    addAndMakeVisible (labelMOSC = new Label (String(), TRANS("MIDI to OSC")));
    labelMOSC->setFont (Font ("Futura", 17.10f, Font::bold));
    labelMOSC->setJustificationType (Justification::centredLeft);
    labelMOSC->setEditable (false, false, false);
    labelMOSC->setColour (Label::textColourId, Colours::white);
    labelMOSC->setColour (TextEditor::textColourId, Colours::black);
    labelMOSC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (loadCalibButton = new TextButton ("loadCalib"));
    loadCalibButton->setButtonText (TRANS("Load Calibration Data"));
    loadCalibButton->addListener (this);
    loadCalibButton->setColour (TextButton::buttonColourId, Colour (0xffadadad));
    loadCalibButton->setColour (TextButton::buttonOnColourId, Colour (0xffc4c4c4));
    loadCalibButton->setColour (TextButton::textColourOnId, Colour (0xff00CC88));
    
    setSize (260, 212);
    
    //==============================================================================
    shiftButton->setToggleState(false, dontSendNotification);
    monoButton->setToggleState(false, dontSendNotification);
    
    startTimer(100); // for timerCallBack(GUI Update)
}

MiditoOscAudioProcessorEditor::~MiditoOscAudioProcessorEditor()
{
    remoteAddressText = nullptr;
    remotePortText = nullptr;
    maxPoly = nullptr;
    glide = nullptr;
    labelPolyphony = nullptr;
    labelGlide = nullptr;
    scaleSelect = nullptr;
    labelScale = nullptr;
    shiftButton = nullptr;
    labelMOSC = nullptr;
    monoButton = nullptr;
    loadCalibButton = nullptr;
}

//==============================================================================
void MiditoOscAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colour (0xff868686));
    
    g.setColour (Colour (0xf5f2f1f1));
    g.fillRoundedRectangle (4.0f, 4.0f, 252.0f, 204.0f, 4.500f);
    
    g.setColour (Colour (0xffadadad));
    g.fillPath (internalPath1);
}

void MiditoOscAudioProcessorEditor::resized()
{
    remoteAddressText->setBounds (11, 180, 115, 20);
    remotePortText->setBounds (132, 180, 115, 20);
    maxPoly->setBounds (69, 34, 185, 24);
    glide->setBounds (69, 60, 185, 24);
    labelPolyphony->setBounds (5, 35, 72, 20);
    labelGlide->setBounds (29, 62, 46, 20);
    scaleSelect->setBounds (44, 119, 203, 20);
    labelScale->setBounds (5, 119, 41, 20);
    shiftButton->setBounds (132, 89, 115, 20);
    labelMOSC->setBounds (3, 6, 150, 24);
    monoButton->setBounds (11, 89, 115, 20);
    loadCalibButton->setBounds (11, 149, 236, 20);
    internalPath1.clear();
    internalPath1.startNewSubPath (4.0f, 9.0f);
    internalPath1.cubicTo (4.0f, 6.0f, 6.0f, 4.0f, 8.0f, 4.0f);
    internalPath1.lineTo (252.0f, 4.0f);
    internalPath1.cubicTo (254.0f, 4.0f, 256.0f, 6.0f, 256.0f, 9.0f);
    internalPath1.lineTo (256.0f, 32.0f);
    internalPath1.lineTo (4.0f, 32.0f);
    internalPath1.closeSubPath();
}

void MiditoOscAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    const OwnedArray<AudioProcessorParameter>& params = getAudioProcessor()->getParameters();
    
    if (sliderThatWasMoved == maxPoly)
    {
        params[Polyphony]->beginChangeGesture();
        params[Polyphony]->setValueNotifyingHost (static_cast<float>( ( maxPoly->getValue() - 1) / 5 ) );
        params[Polyphony]->endChangeGesture();
        
    } else if (sliderThatWasMoved == glide) {
        
        params[Glide]->beginChangeGesture();
        params[Glide]->setValueNotifyingHost (static_cast<float>(glide->getValue()));
        params[Glide]->endChangeGesture();
    }
}

void MiditoOscAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    const OwnedArray<AudioProcessorParameter>& params = getAudioProcessor()->getParameters();
    
    float currentScale = scaleSelect->getSelectedId();
    params[Scale]->beginChangeGesture();
    params[Scale]->setValueNotifyingHost ((currentScale - 1) / 8);
    params[Scale]->endChangeGesture();
    
    static bool _calibMode = false;
    
    if (currentScale == Calib)
    {
        _calibMode = processor.calibMode = true;
        
    } else {
        
        if (_calibMode)
        {
            _calibMode = processor.calibMode = false;
            processor.resetCount();
        }
        
    }
    
    processor.sendScaleValue(scaleSelect->getSelectedId());
}

void MiditoOscAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    const OwnedArray<AudioProcessorParameter>& params = getAudioProcessor()->getParameters();
    
    if (buttonThatWasClicked == shiftButton)
    {
        if (!processor.shiftMode)
        {
            if (processor.monoMode)
            {
                processor.monoMode = false;
                
                params[Mono]->beginChangeGesture();
                params[Mono]->setValueNotifyingHost (static_cast<float>(processor.monoMode));
                params[Mono]->endChangeGesture();
            }
            
            processor.shiftMode = true;
            
        } else {
            
            processor.shiftMode = false;
        }
        
        params[Shift]->beginChangeGesture();
        params[Shift]->setValueNotifyingHost (static_cast<float>(processor.shiftMode));
        params[Shift]->endChangeGesture();
        
        processor.resetCount();
        
    } else if (buttonThatWasClicked == monoButton) {
        
        if (!processor.monoMode)
        {
            if (processor.shiftMode)
            {
                processor.shiftMode = false;
                
                params[Shift]->beginChangeGesture();
                params[Shift]->setValueNotifyingHost (static_cast<float>(processor.shiftMode));
                params[Shift]->endChangeGesture();
            }
            
            processor.monoMode = true;
            
        } else {
            
            processor.monoMode = false;
        }
        
        params[Mono]->beginChangeGesture();
        params[Mono]->setValueNotifyingHost (static_cast<float>(processor.monoMode));
        params[Mono]->endChangeGesture();
        
        processor.resetCount();
        
    } else if (buttonThatWasClicked == loadCalibButton) {
        
        FileChooser ChooseFile("Open Calibration Data", File::getSpecialLocation(File::userHomeDirectory), "*.txt");
        
        if(ChooseFile.browseForFileToOpen())
        {
            const File calibDataText (ChooseFile.getResult());
            
            juce::StringArray calibDataArray;
            calibDataText.readLines(calibDataArray);
            
            for (int i = 0; i < calibDataArray.size(); ++i)
            {
                processor.calibMap[i] = calibDataArray[i].getFloatValue();
            }
        }
        
    }
}

void MiditoOscAudioProcessorEditor::timerCallback()
{
    
    const OwnedArray<AudioProcessorParameter>& params = getAudioProcessor()->getParameters();
    
    for (int i = 0; i < params.size(); ++i)
    {
        const AudioProcessorParameter* param = params[i];
        const float paramValue = param->getValue();
        
        switch (i)
        {
            case Polyphony:
                maxPoly->setValue(paramValue * 5 + 1, dontSendNotification);
                processor.currentMaxPoly = paramValue * 5 + 1;
                break;
                
            case Glide:
                glide->setValue(paramValue, dontSendNotification);
                processor.sendGlideValue(paramValue);
                break;
                
            case Mono:
                processor.monoMode = paramValue;
                
                if (processor.monoMode)
                {
                    if (processor.shiftMode)
                    {
                        shiftButton->setToggleState(false, dontSendNotification);
                        processor.shiftMode = false;
                        
                        params[Shift]->beginChangeGesture();
                        params[Shift]->setValueNotifyingHost (static_cast<float>(processor.shiftMode));
                        params[Shift]->endChangeGesture();
                    }
                    
                    monoButton->setToggleState(true, dontSendNotification);
                    
                } else {
                    
                    monoButton->setToggleState(false, dontSendNotification);
                }
                break;
                
            case Shift:
                processor.shiftMode = paramValue;
                
                if (processor.shiftMode)
                {
                    if (processor.monoMode)
                    {
                        monoButton->setToggleState(false, dontSendNotification);
                        processor.monoMode = false;
                        
                        params[Mono]->beginChangeGesture();
                        params[Mono]->setValueNotifyingHost (static_cast<float>(processor.monoMode));
                        params[Mono]->endChangeGesture();
                    }
                    
                    shiftButton->setToggleState(true, dontSendNotification);
                    
                } else {
                    
                    shiftButton->setToggleState(false, dontSendNotification);
                }
                break;
                
            case Scale:
                scaleSelect->setSelectedId(paramValue * 8 + 1, dontSendNotification);
                processor.sendScaleValue(scaleSelect->getSelectedId());
                break;
                
            default:
                break;
        }
    }
    
    if (reconnect)
    {
        juce::String remotePort = remotePortText->getText();
        processor.setOSCConnection(remoteAddressText->getText(), remotePort.getIntValue());
        reconnect = false;
    }
}

void MiditoOscAudioProcessorEditor::textEditorReturnKeyPressed (TextEditor& textEditorChanged)
{
    reconnect = true;
}
