; ----------------
; --- [*-p] stands for "player"
; ----------------

; ================ Measures
[mPlayer]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=#playerName#
PlayerType=TITLE
DisableLeadingZero=0
;Substitute="":"teraz","π":"•","Í":" ","Ê":"∆","ø":"Ø","ü":"è","ú":"å","Û":"”","Ò":"—","≥":"£"
substitute="":"nie gra"

[mArtist]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=ARTIST
;Substitute="":"Nic nie gra","π":"•","Í":" ","Ê":"∆","ø":"Ø","ü":"è","ú":"å","Û":"”","Ò":"—","≥":"£"
substitute="":"Nikt nic"

[mAlbum]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=ALBUM
;Substitute="":"Play something";,"π":"•","Í":" ","Ê":"∆","ø":"Ø","ü":"è","ú":"å","Û":"”","Ò":"—","≥":"£"

[mDate]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=YEAR

[mCover]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=COVER
;Substitute="":"Default.png"

[mPosition]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=POSITION

[mDuration]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=DURATION

[mProgress]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=PROGRESS

[mRating]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=RATING

[mState]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mPlayer]
PlayerType=STATE
IfEqualValue=1
IfEqualAction=[!hidemeter state-p]
IfAboveValue=1
IfAboveAction=[!showmeter state-p]
IfBelowValue=1
IfBelowAction=[!hidemeter state-p]

; ================ Meters
[player-seg]
meter=image
meterstyle=separator
X=-1r

[cover-note]
meter=image
X=-[bg:H]r
Y=([bg:Y]+2)
H=([bg:H]-4)
W=([bg:H]-4)
path=#@#images
imagename=note
solidcolor=#t.color2#
imagetint=20,20,20
antialias=1

[cover]
meter=image
measurename=mCover
X=r
Y=r
H=([bg:H]-4)
W=([bg:H]-4)
antialias=1
LeftMouseUpAction=!Execute [!CommandMeasure mPlayer OpenPlayer]

[state-p]
meter=image
X=r
Y=r
H=([bg:H]-4)
W=([bg:H]-4)
antialias=1
path=#@#images
imagename=state-p.png

[cover-b]
meter=image
X=r
Y=r
H=([bg:H]-4)
W=([bg:H]-4)
path=#@#images
imagename=cover-b
antialias=1

[cover-f]
meter=image
X=r
Y=r
H=([bg:H]-4)
W=([bg:H]-4)
path=#@#images
imagename=c-glow
antialias=1

[timebar]
meter=bar
measurename=mProgress
X=-3r
Y=r
W=1
H=[cover:H]
solidcolor=#t.color3#
barcolor=#t.color#
barorientation=vertical

[title-player]
meter=string
measurename=mPlayer
meterstyle=value
X=-4r
stringalign=right
clipstring=2
clipstringW=250
dynamicvariables=1
group=p.norm

[artist-player]
meter=string
measurename=mArtist
meterstyle=label
X=([title-player:X])
stringalign=right
dynamicvariables=1
;W=(274-[title-player:W])
clipstring=2
clipstringW=(400-[title-player:W])
group=p.norm

[hoverPlayer]
meter=image
solidcolor=0,0,0,0
X=([timebar:X]-400)
Y=[bg:Y]
W=400
H=[bg:H]
MouseOverAction=!Execute [!ShowMeterGroup p.hov][!HideMeterGroup p.norm][!Redraw]
MouseLeaveAction=!Execute [!HideMeterGroup p.hov][!ShowMeterGroup p.norm][!Redraw]

[elapsedtime]
meter=string
measurename=mPosition
meterstyle=value
X=-6R
stringalign=right
dynamicvariables=1
group=p.hov
W=48
clipstring=1
hidden=1

[nextbutton]
meter=string
meterstyle=value
fontface=webdings
X=-60r
Y=([bg:Y]+(([bg:H]-4)/2)-4)
fontsize=10
text=8
group=p.hov
hidden=1
mouseoveraction=!Execute [!SetOption nextbutton FontColor #h.color#][!updatemeter nextbutton][!Redraw]
mouseleaveaction=!Execute [!SetOption nextbutton FontColor ""][!SetOption album-p text ""][!updatemeter album-p][!updatemeter nextbutton][!Redraw]
LeftMouseUpAction=!Execute [!CommandMeasure mPlayer Next][!SetOption album-p text "%2"][!updatemeter album-p][!Redraw]
;ToolTipText=Next

[prevbutton]
meter=string
meterstyle=value
fontface=webdings
X=-16r
Y=r
W=15
fontsize=10
text=7
group=p.hov
hidden=1
mouseoveraction=!Execute [!SetOption prevbutton FontColor #h.color#][!updatemeter prevbutton][!Redraw]
mouseleaveaction=!Execute [!SetOption prevbutton FontColor ""][!SetOption album-p text ""][!updatemeter prevbutton][!Redraw]
LeftMouseUpAction=!Execute [!CommandMeasure mPlayer Previous][!SetOption album-p text "%2"][!updatemeter album-p][!Redraw]
;ToolTipText=Previous

[Stars-p]
Meter=BITMAP
X=-70r
Y=r
MeasureName=mRating
BitmapImage=#@#images\Rating.png
BitmapFrames=6
BitmapZeroFrame=1
group=p.hov
hidden=1

[album-p]
meter=string
measurename=mAlbum
measurename2=mPlayer
meterstyle=value
X=-10r
stringalign=right
dynamicvariables=1
clipstring=2
clipstringW=270
group=p.hov
hidden=1

[date-p]
meter=string
measurename=mDate
meterstyle=label
X=([album-p:X])
dynamicvariables=1
stringalign=right
clipstring=2
clipstringW=30
group=p.hov
hidden=1

;[setRating1]
;meter=image
;X=10r
;Y=r
;W=13
;H=10
;solidcolor=0,0,0,1
;LeftMouseUpAction=!Execute [!CommandMeasure "mPlayer" "SetRating" 1]


[playbutton]
meter=image
solidcolor=0,0,0,0
hidden=1
group=p.hov
X=[hoverPlayer:X]
Y=[hoverPlayer:Y]
W=230
H=[hoverPlayer:H]
LeftMouseUpAction=!Execute [!CommandMeasure mPlayer PlayPause]
ToolTipText="Play/pause"

