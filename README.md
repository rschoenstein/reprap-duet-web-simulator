# Reprap Duet Web Simulator

## Simulates output of the Reprap Duet 0.85, firmware version 1.1

### Why?
Using this to test a Duet control mobile app I'm currently working on. I wouldn't want to send (possibly damaging) commands to my 3D printer.


### So... it looks incomplete. Does it work?
I have only implemented the rr_connect, rr_disconnect, and rr_status handlers so far. The others return a null JSON string for now.


