# libUI
A framework designed for arduino application development.  
# Features  
## Pages  
Multi-function management system. Write multiple "applications", each have its own `setup` and `loop`, just like a normal Arduino program.  
These individual function unit is called "Page".  
## Controls  
Controls are the units of drawable items. Forexample, we currently have `Label`, which is a text feild. Each control have its background and foreground color.  
If you are familiar with Winform, it has "Control" of similar meaning.  
## Layouts  
Layouts are a special type of controls. It decides how Controls are layed out. When it is drawn, it firstly draws its "frame", then draw each Control in its containers. 
## Events  
The event system is still under development and not being released. The idea is to bind a event for hardware buttons, and more interruptable events in the future.  
# Dependencies  
## Ucglib  
Drawing backend for tft lcds.  
## Arduino core  
This lib is designed for stm32duino. It should be compatible with a generic Arduino, as long as Ucglib supports it and it have enough flash and RAM.  
## *PlatformIO  
Not required. this lib is developed and debugged under PlatformIO. Using generic Arduino IDE should not be a problem.
