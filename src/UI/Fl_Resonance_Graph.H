/*
  ZynAddSubFX - a software synthesizer

  Fl_Resonance_Graph.H - OSC Resonance Graph View
  Copyright (C) 2016 Mark McCurry

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.
*/
// generated by Fast Light User Interface Designer (fluid) version 1.0302

#ifndef Fl_Resonance_Graph_H
#define Fl_Resonance_Graph_H
#include <FL/Fl_Box.H>
#include "../Synth/Resonance.h"
#include "Fl_Osc_Widget.H"

class Fl_Value_Output;
class Fl_Widget;
class Fl_Resonance_Graph : public Fl_Box, public Fl_Osc_Widget {
    public:
        Fl_Resonance_Graph(int x,int y, int w, int h, const char *label=0);
        virtual ~Fl_Resonance_Graph(void);
        void init(Fl_Value_Output *khzvalue_,Fl_Value_Output *dbvalue_);
        void draw_freq_line(float freq,int type);
        void draw();
        int handle(int event);
        void setcbwidget(Fl_Widget *cbwidget,Fl_Widget *applybutton);
        void update(void);

        float khzval; 

        void OSC_raw(const char *msg);

    private:
        float getfreqx(float x) const;
        float getfreqpos(float freq) const;
        float getcenterfreq() const;
        float getoctavesfreq() const;

        void setPoint(int idx, int val);

        Fl_Value_Output *khzvalue; 
        Fl_Value_Output *dbvalue; 
        int oldx,oldy; 
        Fl_Widget *cbwidget,*applybutton; 

        //duplicate data required to render response
        unsigned char Prespoints[N_RES_POINTS];
        char Pcenterfreq;
        char Poctavesfreq;
        char PmaxdB;
};
#endif
