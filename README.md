# ofxXeThru
openframeworks code specifically for use with XeThru - X4M200 https://www.xethru.com/x4m200-respiration-sensor.html
MAC OS 10.12
OF v9.8

## How to Build: 

1. Open project generator and add ofxXeThru in your addon section and create / update you project. When you open Xcode all the header files in the '/src' folder should be linked in your 'header search path section' if not you'll need to manually enter them. 

2. Open finder and drag in the 'lib/libModuleConnector.dylib' into the xcode sidebar underneath 'addons/ofxXeThru'
![Alt Text](https://github.com/fakelove/ofxXeThru/blob/master/example/bin/data/shot3.gif?raw=true)

3. IMPORTANT You can run the 'lib/install_lib' script I've provided. It's literally a single line that copies the 'libModuleConnector.dylib' into the 'usr/local/lib' but you can just as easily do this manually.

4. In Xcode do the following:

* Drag the 'libModuleConnector.dylib' from the left sidebar into the 'Target > Build Phases > Link Binary with Libraries'
![Alt Text](https://github.com/fakelove/ofxXeThru/blob/master/example/bin/data/shot2.gif?raw=true)

* Go to 'Build Settings > Library Search Paths' and add '../../../addons/ofxXeThru/lib' so Xcode can get to the path for the .dylib 
![Alt Text](https://github.com/fakelove/ofxXeThru/blob/master/example/bin/data/shot1.gif?raw=true)

