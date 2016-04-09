/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUIComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUIComponents::GUIComponents ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (remoteAddressText = new TextEditor ("IP"));
    remoteAddressText->setMultiLine (false);
    remoteAddressText->setReturnKeyStartsNewLine (false);
    remoteAddressText->setReadOnly (false);
    remoteAddressText->setScrollbarsShown (false);
    remoteAddressText->setCaretVisible (true);
    remoteAddressText->setPopupMenuEnabled (true);
    remoteAddressText->setText (TRANS("127.0.0.1"));

    addAndMakeVisible (remotePortText = new TextEditor ("port"));
    remotePortText->setMultiLine (false);
    remotePortText->setReturnKeyStartsNewLine (false);
    remotePortText->setReadOnly (false);
    remotePortText->setScrollbarsShown (true);
    remotePortText->setCaretVisible (true);
    remotePortText->setPopupMenuEnabled (true);
    remotePortText->setText (TRANS("9000"));

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

    addAndMakeVisible (labelPolyphony = new Label (String(),
                                                   TRANS("Polyphony\n")));
    labelPolyphony->setFont (Font ("Futura", 14.00f, Font::plain));
    labelPolyphony->setJustificationType (Justification::centredLeft);
    labelPolyphony->setEditable (false, false, false);
    labelPolyphony->setColour (Label::textColourId, Colour (0xff363636));
    labelPolyphony->setColour (TextEditor::textColourId, Colours::black);
    labelPolyphony->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (labelGlide = new Label (String(),
                                               TRANS("Glide")));
    labelGlide->setFont (Font ("Futura", 14.00f, Font::plain));
    labelGlide->setJustificationType (Justification::centredLeft);
    labelGlide->setEditable (false, false, false);
    labelGlide->setColour (Label::textColourId, Colour (0xff363636));
    labelGlide->setColour (TextEditor::textColourId, Colours::black);
    labelGlide->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ScaleSelect = new ComboBox ("scale"));
    ScaleSelect->setEditableText (false);
    ScaleSelect->setJustificationType (Justification::centred);
    ScaleSelect->setTextWhenNothingSelected (TRANS("Chromatic"));
    ScaleSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    ScaleSelect->addItem (TRANS("Chromatic"), 1);
    ScaleSelect->addItem (TRANS("Major"), 2);
    ScaleSelect->addItem (TRANS("M7"), 3);
    ScaleSelect->addItem (TRANS("Min7"), 4);
    ScaleSelect->addItem (TRANS("Dorian"), 5);
    ScaleSelect->addItem (TRANS("Minor"), 6);
    ScaleSelect->addItem (TRANS("5th"), 7);
    ScaleSelect->addItem (TRANS("Whole"), 8);
    ScaleSelect->addListener (this);

    addAndMakeVisible (labelScale = new Label (String(),
                                               TRANS("Scale\n")));
    labelScale->setFont (Font ("Futura", 14.00f, Font::plain));
    labelScale->setJustificationType (Justification::centredLeft);
    labelScale->setEditable (false, false, false);
    labelScale->setColour (Label::textColourId, Colour (0xff363636));
    labelScale->setColour (TextEditor::textColourId, Colours::black);
    labelScale->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (shiftButton = new TextButton ("shiftFlag"));
    shiftButton->setButtonText (TRANS("Shift"));
    shiftButton->addListener (this);
    shiftButton->setColour (TextButton::buttonColourId, Colour (0xffadadad));
    shiftButton->setColour (TextButton::buttonOnColourId, Colour (0xffc4c4c4));
    shiftButton->setColour (TextButton::textColourOnId, Colour (0xff363636));

    addAndMakeVisible (labelMOSC = new Label (String(),
                                              TRANS("MIDI to OSC")));
    labelMOSC->setFont (Font ("Futura", 17.10f, Font::bold));
    labelMOSC->setJustificationType (Justification::centredLeft);
    labelMOSC->setEditable (false, false, false);
    labelMOSC->setColour (Label::textColourId, Colours::white);
    labelMOSC->setColour (TextEditor::textColourId, Colours::black);
    labelMOSC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (monoButton = new TextButton ("monoFlag"));
    monoButton->setButtonText (TRANS("Mono"));
    monoButton->addListener (this);
    monoButton->setColour (TextButton::buttonColourId, Colour (0xffadadad));
    monoButton->setColour (TextButton::buttonOnColourId, Colour (0xffc4c4c4));
    monoButton->setColour (TextButton::textColourOnId, Colour (0xff363636));

    addAndMakeVisible (loadCalibButton = new TextButton ("loadCalib"));
    loadCalibButton->setButtonText (TRANS("Load Calibration Data"));
    loadCalibButton->addListener (this);
    loadCalibButton->setColour (TextButton::buttonColourId, Colour (0xffadadad));
    loadCalibButton->setColour (TextButton::buttonOnColourId, Colour (0xffc4c4c4));
    loadCalibButton->setColour (TextButton::textColourOnId, Colour (0xff363636));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUIComponents::~GUIComponents()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    remoteAddressText = nullptr;
    remotePortText = nullptr;
    maxPoly = nullptr;
    glide = nullptr;
    labelPolyphony = nullptr;
    labelGlide = nullptr;
    ScaleSelect = nullptr;
    labelScale = nullptr;
    shiftButton = nullptr;
    labelMOSC = nullptr;
    monoButton = nullptr;
    loadCalibButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUIComponents::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff878686));

    g.setColour (Colour (0xf5f2f1f1));
    g.fillRoundedRectangle (4.0f, 4.0f, 252.0f, 204.0f, 4.500f);

    g.setColour (Colour (0xffaea8a8));
    g.fillPath (internalPath1);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUIComponents::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    remoteAddressText->setBounds (11, 180, 115, 20);
    remotePortText->setBounds (132, 180, 115, 20);
    maxPoly->setBounds (69, 34, 185, 24);
    glide->setBounds (69, 60, 185, 24);
    labelPolyphony->setBounds (5, 35, 72, 20);
    labelGlide->setBounds (29, 62, 46, 20);
    ScaleSelect->setBounds (44, 119, 203, 20);
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

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUIComponents::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == maxPoly)
    {
        //[UserSliderCode_maxPoly] -- add your slider handling code here..
        //[/UserSliderCode_maxPoly]
    }
    else if (sliderThatWasMoved == glide)
    {
        //[UserSliderCode_glide] -- add your slider handling code here..
        //[/UserSliderCode_glide]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUIComponents::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == ScaleSelect)
    {
        //[UserComboBoxCode_ScaleSelect] -- add your combo box handling code here..
        //[/UserComboBoxCode_ScaleSelect]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void GUIComponents::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == shiftButton)
    {
        //[UserButtonCode_shiftButton] -- add your button handler code here..
        //[/UserButtonCode_shiftButton]
    }
    else if (buttonThatWasClicked == monoButton)
    {
        //[UserButtonCode_monoButton] -- add your button handler code here..
        //[/UserButtonCode_monoButton]
    }
    else if (buttonThatWasClicked == loadCalibButton)
    {
        //[UserButtonCode_loadCalibButton] -- add your button handler code here..
        //[/UserButtonCode_loadCalibButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUIComponents" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff878686">
    <ROUNDRECT pos="4 4 252 204" cornerSize="4.5" fill="solid: f5f2f1f1" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ffaea8a8" hasStroke="0" nonZeroWinding="1">s 4 9.25 c 4 6.37 6.02 4  8.5 4 l 251.5 4 c 253.98 4 256 6.37  256 9.25 l 256 32 l 4 32 x</PATH>
  </BACKGROUND>
  <TEXTEDITOR name="IP" id="9e067175757a2ce2" memberName="remoteAddressText"
              virtualName="" explicitFocusOrder="0" pos="11 180 115 20" initialText="127.0.0.1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="port" id="d68185094e55f4a8" memberName="remotePortText"
              virtualName="" explicitFocusOrder="0" pos="132 180 115 20" initialText="9000"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="Polyphony" id="80c9408b5df7114d" memberName="maxPoly" virtualName=""
          explicitFocusOrder="0" pos="69 34 185 24" thumbcol="ff909eb4"
          min="1" max="6" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="14" skewFactor="1"/>
  <SLIDER name="Glide" id="833687669baa14f4" memberName="glide" virtualName=""
          explicitFocusOrder="0" pos="69 60 185 24" thumbcol="ff909eb4"
          min="0" max="1" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="30"
          textBoxHeight="14" skewFactor="1"/>
  <LABEL name="" id="e79c4111330a32e4" memberName="labelPolyphony" virtualName=""
         explicitFocusOrder="0" pos="5 35 72 20" textCol="ff363636" edTextCol="ff000000"
         edBkgCol="0" labelText="Polyphony&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Futura"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="a3d8b375a0870336" memberName="labelGlide" virtualName=""
         explicitFocusOrder="0" pos="29 62 46 20" textCol="ff363636" edTextCol="ff000000"
         edBkgCol="0" labelText="Glide" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Futura" fontsize="14" bold="0"
         italic="0" justification="33"/>
  <COMBOBOX name="scale" id="83509f079d45f498" memberName="ScaleSelect" virtualName=""
            explicitFocusOrder="0" pos="44 119 203 20" editable="0" layout="36"
            items="Chromatic&#10;Major&#10;M7&#10;Min7&#10;Dorian&#10;Minor&#10;5th&#10;Whole"
            textWhenNonSelected="Chromatic" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="e04a1276c4f86ed8" memberName="labelScale" virtualName=""
         explicitFocusOrder="0" pos="5 119 41 20" textCol="ff363636" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Futura" fontsize="14" bold="0"
         italic="0" justification="33"/>
  <TEXTBUTTON name="shiftFlag" id="f8ce5fbaa20eb33c" memberName="shiftButton"
              virtualName="" explicitFocusOrder="0" pos="132 89 115 20" bgColOff="ffadadad"
              bgColOn="ffc4c4c4" textCol="ff363636" buttonText="Shift" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="" id="d1a51ada5e4517ca" memberName="labelMOSC" virtualName=""
         explicitFocusOrder="0" pos="3 6 150 24" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="MIDI to OSC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Futura"
         fontsize="17.100000000000001421" bold="1" italic="0" justification="33"/>
  <TEXTBUTTON name="monoFlag" id="cce45a3601f891a7" memberName="monoButton"
              virtualName="" explicitFocusOrder="0" pos="11 89 115 20" bgColOff="ffadadad"
              bgColOn="ffc4c4c4" textCol="ff363636" buttonText="Mono" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="loadCalib" id="c2dd4b96c759358a" memberName="loadCalibButton"
              virtualName="" explicitFocusOrder="0" pos="11 149 236 20" bgColOff="ffadadad"
              bgColOn="ffc4c4c4" textCol="ff363636" buttonText="Load Calibration Data"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
