#! /bin/bash

BASEDIR=$(cd "$(dirname "$0")"; pwd)
CSS_THEME=./DMW--theme.css
"$BASEDIR"/convert_presentation.sh Digital_Music_Workshop--00--Digital_Sound_Basics $CSS_THEME
"$BASEDIR"/convert_presentation.sh Digital_Music_Workshop--01--Electronic_Music_Protocols+Inter-Application+Device_Communication $CSS_THEME
"$BASEDIR"/convert_presentation.sh Digital_Music_Workshop--02--Digital_Audio_Signal_Processing $CSS_THEME
"$BASEDIR"/convert_presentation.sh Digital_Music_Workshop--03--Music_Basics $CSS_THEME
"$BASEDIR"/convert_presentation.sh Digital_Music_Workshop--04--Algorithmic_Compositions_Basics $CSS_THEME
"$BASEDIR"/convert_presentation.sh Digital_Music_Workshop--05--Digital_Audio_on_MCU $CSS_THEME
