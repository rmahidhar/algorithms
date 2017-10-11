package com.algorithms.processing.sample;

/**
 * Created by mahidhar on 4/24/17.
 */
import processing.core.PApplet;

public class UsingProcessing extends PApplet{

    public static void main(String[] args) {
        PApplet.main("com.algorithms.processing.sample.UsingProcessing");
    }

    public void settings(){
        size(300,300);
    }

    public void setup(){
        fill(120,50,240);
    }

    public void draw(){
        ellipse(width/2,height/2,second(),second());
    }
}