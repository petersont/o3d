Notes about these assets.

They were created by Crazy Pixel Productions.
http://www.crazypixelproductions.com/

source_assets/Terrain/terrainLayout.max is the original scene

It correctly references the original textures (the .TGA and .PSD files).
That scene can be processed by source_assets/process_assets.py (python)
assuming that a copy of 3dsmax 2009 is installed, that the ColladaMax plugin
is installed, the DirectX SDK is installed, and the paths inside
process_assets.py are updated to point to those installations.

Terrain/terrainWithDDS.max is a scene where the artists edited the DDS files
directly that resulted from the step above. I would have preferred they
edited the source files but they didn't so I just went with that they had.
So, this max file references the textures in
source_assets/external/Terrain/beachdemo/assets/images

Terrain/terrainWithDDS-flattened-particles.max is the same scene
as terrainWithDDS.max except the ocean and skydome have been deleted
since those are done programatically, the instances have been collapsed
meaning for example the 70 instances of 1 model, TreeA, have been converted
to 1 model of 70 trees, and dummies have been added to mark where to
put particle emitters at runtime.

To generate the loadable file, run:

   o3dConverter beachdemo-exported-from-max.dae assets/beachdemo.o3dtgz
