/* receiving and sending OSC messages */

import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress mRemoteLocation;

void setup() {
    size(640, 480);
    background(0);
    oscP5 = new OscP5(this, 7000);
    mRemoteLocation = new NetAddress("127.0.0.1", 7001);
}

void draw() {
}

void mousePressed() {
    OscMessage myMessage = new OscMessage("/note_on");
    myMessage.add(48);
    myMessage.add(100);
    oscP5.send(myMessage, mRemoteLocation); 

    println("+++ sent message:");
    print(" addrpattern: "+myMessage.addrPattern());
    println(" typetag: "+myMessage.typetag());
}


void oscEvent(OscMessage pOscMessage) {
    print("+++ received an osc message:");
    print(" addrpattern: "+pOscMessage.addrPattern());
    println(" typetag: "+pOscMessage.typetag());
}
