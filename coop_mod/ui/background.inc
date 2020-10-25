resource 
RenderModel
{
ordernumber 0
name "Default"
rect 0 0 640 480
fgcolor 0.00 0.00 0.00 1.00
bgcolor 0.35 0.67 1.00 1.00

rendermodelprecache
rendermodel /models/sky/sky_UI-stardome02.tik
linkcvar "ui_mainMenuModel"
rendermodeloffset "0 0 0"
rendermodelrotateoffset "0 0 0"
rendermodelanimation "idle"
rendermodelfov 60.0 45.0

visibilityProperty "Background" "ShowShip"
}


resource
Widget
{
name "main_bkg_01"
rect 0 0 256 256
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "none"
ordernumber 1
shader menu/main/bkg_01
}

resource
Widget
{
name "main_bkg_02"
rect 256 0 256 256
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "none"
ordernumber 1
shader menu/main/bkg_02
}

resource
Widget
{
name "main_bkg_03"
rect 512 0 128 256
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "none"
ordernumber 1
shader menu/main/bkg_03
}

resource
Widget
{
name "main_bkg_04"
rect 0 256 256 256
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "none"
ordernumber 1
shader menu/main/bkg_04
}

resource
Widget
{
name "main_bkg_05"
rect 256 256 256 256
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "none"
ordernumber 1
shader menu/main/bkg_05
}

resource
Widget
{
name "main_bkg_06"
rect 512 256 128 256
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "none"
ordernumber 1
shader menu/main/bkg_06
}

resource
Widget
{
name "logo"
rect 174 -29 288 134
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "none"
ordernumber 10
shader menu/main/logo
}



end.
