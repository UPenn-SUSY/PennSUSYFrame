#!/usr/bin/env python

from ROOT import *

def ATLASLabel(x, y, color=1, flag = ''):
    l = TLatex()
    tsize=0.040
    #l.SetTextAlign(12)
    l.SetTextSize(tsize);
    l.SetNDC()
    l.SetTextFont(72)
    l.SetTextColor(color)
    l.DrawLatex(x,y,"ATLAS")
    if not flag == '':
        f = TLatex()
        f.SetNDC()
        f.SetTextFont(42)
        f.SetTextColor(color)
        f.SetTextSize(tsize);
        f.DrawLatex(x+0.125,y,flag)
        # f.DrawLatex(x+0.155,y,flag)

def myText(x, y, color, text):
    tsize=0.040
    l = TLatex()
    #l.SetTextAlign(12)
    l.SetTextSize(tsize)
    l.SetNDC()
    l.SetTextColor(color)
    l.DrawLatex(x,y,text)


def myBoxText(x, y, boxsize, mcolor, text):
    tsize=0.06

    l = TLatex()
    l.SetTextAlign(12)
    #l.SetTextSize(tsize)
    l.SetNDC()
    l.DrawLatex(x,y,text)

    y1=y-0.25
    y2=y+0.25
    x2=x-0.3
    x1=x2-boxsize

    # print "x1= %f x2= %f y1= %f y2= %f \n" % (x1,x2,y1,y2)

    mbox = TPave(x1,y1,x2,y2,0,"NDC")

    mbox.SetFillColor(mcolor)
    mbox.SetFillStyle(1001)
    mbox.Draw()

    mline = TLine()
    mline.SetLineWidth(4)
    mline.SetLineColor(1)
    mline.SetLineStyle(1)
    y=(y1+y2)/2.
    mline.DrawLineNDC(x1,y,x2,y)


def myMarkerText(x, y, color, mstyle, text, msize=2.):
    tsize = 0.06
    marker = TMarker(x-(0.4*tsize),y,8)
    marker.SetMarkerColor(color)
    marker.SetNDC()
    marker.SetMarkerStyle(mstyle)
    marker.SetMarkerSize(msize)
    marker.Print()
    marker.Draw()
    #marker.DrawMarker(x-(0.4*tsize),y)
    #marker.PaintMarker(x-(0.4*tsize),y)
    marker.Print()

    # print str(x-(0.4*tsize)) + ' -- ' + str(y)

    l = TLatex()
    l.SetTextAlign(12)
    #l.SetTextSize(tsize)
    l.SetNDC()
    l.DrawLatex(x,y,text)
