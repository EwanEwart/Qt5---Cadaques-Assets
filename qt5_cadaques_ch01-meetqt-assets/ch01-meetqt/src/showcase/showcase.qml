
/*
 * Copyright (c) 2013, Juergen Bocklage-Ryannel, Johan Thelin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the editors nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// showcase.qml

//import QtQuick 2.5 // EE--
import QtQuick
// EE++

//////////
// FastBlur
// import QtGraphicalEffects 1.0 // EE--
import Qt5Compat.GraphicalEffects

// EE++
Image {
    id: rootImg
    source: "images/background.png"
    // width, height, ... derived from Image rootImg
    property int blurRadius: 0

    Image {
        id: pole
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "images/pole.png"
    }

    Image {
        id: wheelImg
        source: "images/pinwheel.png"
        anchors.centerIn: parent
        // anchors.horizontalCenterOffset: 10 // EE++ EE--
        Behavior on rotation {
            NumberAnimation {
                easing.type: Easing.OutInQuad
                duration: 1000 // [ms]
            }
        }
        layer.enabled: true
        layer.effect: FastBlur {
            id: blur
            radius: rootImg.blurRadius
            Behavior on radius {
                NumberAnimation {
                    duration: 250 // [ms]
                }
            }
        }
    }

    MouseArea {
        acceptedButtons: Qt.LeftButton | Qt.RightButton // EE++


        /* The mouse area emits "signals"
            when the user clicks inside the area
            it covers.
           You can connect to this signal
            by overwriting the "onClicked" / "onPressed"
            handler/function.
        */

        // anchors.fill: parent // EE--
        anchors.fill: wheelImg // EE++
        // EE++
        // onClicked: { // handler / function
        //     wheelImg.rotation += 90
        //     rootImg.blurRadius = 16
        // }

        // overwrite handler / function
        onPressed: {

            if (pressedButtons & Qt.LeftButton)
                // EE++
                // mathematical direction of rotation == anti clock wise
                wheelImg.rotation -= 90
            else if (pressedButtons & Qt.RightButton)
                // EE++
                // anti mathematical direction of rotation == clock wise
                wheelImg.rotation += 90
            else
                // nothing to do
                rootImg.blurRadius = 16
        }

        // overwrite handler / function
        onReleased: {
            // wheelImg stays where it is // EE++
            rootImg.blurRadius = 0
        }
    }
}
/*
Note

This technique works for every signal,
with the naming convention being on + SignalName capitalised.

Also, all properties emit a signal
when their value changes.
For these signals, the naming convention is:

    on + PropertyName + Changed

For example, if a width property is changed,
you can observe it with

    onWidthChanged: print(width)

*/

