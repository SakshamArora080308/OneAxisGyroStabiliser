# OneAxisGyroStabiliser
One Axis Gyroscopic Stabiliser (code lost due to an unexpected error in the laptop) 
## Brief
A one-axis gyroscopic stabiliser balances an object despite changes in the pitch. The pitch changes can also be gathered from the serial monitor and a graph can be plotted to see how the pitch varied in a specific interval of time. The project uses an MPU6050 sensor to detect and counteract tilt.
## Connection To Aerospace 
A gyroscopic stabiliser is used to stabilise aircraft in one axis. For example, a gust of wind can exert a force large enough to change the pitch of a drone; however, a gyroscopic stabiliser would detect this change and send a counter-response signal to the motors to bring the drone back to level. This is also the technology used to keep aircraft stable when in autopilot. 
## Installation (Core Stabilisation) 
The installation of the first prototype was straightforward. I connected an MPU6050 sensor and a servo motor to an Arduino and used the formula ```pitch= a_x/sqrt(a_y * a_y + a_z * a_z)``` to calculate the pitch. 
Then, I mapped the pitch and the servo using the ```map()``` function in Arduino IDE. This looked like ```angle = map(pitch,-90,90,180,0)```. 
Specifically:
1)For a -90 degree pitch, the servo would turn to 180 degrees to counteract the effect.
2)For a 90 degree pitch, the servo would turn to 0 degrees to counteract the effect.
3)For a leveled, 0 degree pitch, the servo would stay at 90 degrees.
4) For any pitch angle in between, the ```map()``` function interpolates the angle.
## Installation (Enhancements) 
In this stage, I added an LCD to display the pitch in real time, and I added a tilt switch and a buzzer. This was done so that if the tilt becomes large enough to rotate the ball inside the tilt switch, the buzzer will sound.
## Learnings 
In this project, I learnt various useful functions. Firstly, I learnt how to use the ```map()``` function which made programming easier since I didn't have to manually do the maths for the linear interpolation. 
Secondly, I learnt how to handle sensor noises; The sensor values fluctuated between 0.8 and -0.8 due to the inaccuracy of the sensor, so I added a code stating that ```if(pitch>=-0.8 && pitch<=0.8){ pitch=0;}``` so that the pitch would be exactly 0 at level. 
I also learnt about the ```millis()``` function since I wanted the LCD to display the data every 500ms to reduce the flickering effect while not compromising on the reaction time of the servo. 
## Future Scope 
I plan to revisit this project once I gather more electronic supplies, such as additional servos to expand this project into the 2nd and 3rd axis, so that it could also measure and counteract roll and yaw. I also plan to make a blackbox-like effect by exporting the serial monitor data into Microsoft Excel and graphing the pitch at different times and detecting when certain switches were pressed, or when the buzzer goes off 
## END
Unfortunately, the code for this project got deleted as I had not saved it and my laptop rebooted. However, the related pictures and videos can be found in the other file in this repository
