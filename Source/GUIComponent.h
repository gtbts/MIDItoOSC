/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_BD6DB57C2CE45C03__
#define __JUCE_HEADER_BD6DB57C2CE45C03__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUIComponents  : public Component,
                       public SliderListener,
                       public ComboBoxListener,
                       public ButtonListener
{
public:
    //==============================================================================
    GUIComponents ();
    ~GUIComponents();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextEditor> remoteAddressText;
    ScopedPointer<TextEditor> remotePortText;
    ScopedPointer<Slider> maxPoly;
    ScopedPointer<Slider> glide;
    ScopedPointer<Label> labelPolyphony;
    ScopedPointer<Label> labelGlide;
    ScopedPointer<ComboBox> ScaleSelect;
    ScopedPointer<Label> labelScale;
    ScopedPointer<TextButton> shiftButton;
    ScopedPointer<Label> labelMOSC;
    ScopedPointer<TextButton> monoButton;
    ScopedPointer<TextButton> loadCalibButton;
    Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIComponents)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_BD6DB57C2CE45C03__
