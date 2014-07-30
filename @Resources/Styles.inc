; new ==============
[line]
solidcolor=0,200,0,00
X=R
Y=([bg:Y])
W=1
H=([bg:H])

[separator]
solidcolor=255,250,245,50
X=R
Y=([bg:Y]+(([bg:H]-10)/2))
W=1
H=10

; --- text
[label]
X=6R
Y=([bg:Y]+(([bg:H]-#t.height#)/2))
H=#t.height#
fontface=segoe ui 
fontsize=8
fontcolor=255,250,245,150
stringstyle=normal
;stringcase=normal
stringalign=left
antialias=1

[value]
X=R
Y=([bg:Y]+(([bg:H]-#t.height#)/2))
H=#t.height#
fontface=segoe ui 
fontsize=8
fontcolor=255,255,255,255
stringstyle=bold
;stringcase=normal
stringalign=left
antialias=1
stringeffect=shadow
fonteffectcolor=0,0,0,20

