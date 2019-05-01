# Elevator_Simulation


Elevator designed using HTML, CSS, JVASCRIPT.
Floors are created dynamically using Controller Function

Javascript code is divided into 3 asses: 
1) Button
2) Floor
3) Elevator

# Controller 


having two functions to call 
a) buttonPressed()- Abstract method overridden my Button class method
b) handleRequest() function to manage your request. If correct then call Elevator class function with two parameters direction and floor


# Button class
having 3 functions to call

a) buttonPressed:- Overridden function sending information like two parameters buttonType, buttonFloor to handleRequest()unction.
b) Button class also consist of 3 parameters buttonType, floorNum, floorId.

# Floor class 
having function initDisplay() to show Floor with floorNum on webPage.

# Elevator class 
having 4 functions to call
a) initDisplay():- Display Elevator number (like for single elevator system, it will display Elevator 0 on our webpage)
b) statusDisplay() :- It will display direction and floor no. 
c)assignJob():- It will call statusDisplay() and use Timeout() function to delay display according to the floor difference between current floor and destination floor
d)isEligable():- checks direction and if eligable returns distance else returns -1.README
