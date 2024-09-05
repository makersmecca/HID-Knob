## HID based Knob Using Arduino Micro ##
## README ##
A completely customizable, multi-purpose input device that can be programmed to fit your needs. By default, it has four modes that can be switched using the Dial's push switch capability.<br/>
The four default modes are:
<ol>
  <li>System Master Volume Control</li>
  <li>Switch between Active Windows</li>
  <li>Switch between Browser Tabs</li>
  <li>Zoom in/out of a webpage</li>
</ol>
The currently active mode is indicated using two onboard LED lamps, where each lamp represents one bit [(00, 01, 10, 11)<sub>2</sub> => (0,1,2,3)<sub>10</sub>] <br/> 
<br/>
The device also comes with 3 capacitive touch-sensitive switches, each having their functionalities. By default, these are set to:
<ul>
  <li>Mute/Unmute microphone</li>
  <li>DND on/off</li>
  <li>Lock Device</li>
</ul>



Components Used:
•	Arduino Pro micro (or any dev board with native HID support)
•	Rotary Encoder
•	Capacitive Touch Switch (X3)
•	SMD LED (x2)
•	1K Resistors (x2)
•	Aluminium Composite Board for base

Library used:
NicoHood HID library
https://github.com/NicoHood/HID.git

