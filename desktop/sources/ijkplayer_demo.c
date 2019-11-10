/*****************************************************************************
* ijkplayer_demo.c
*****************************************************************************
*
* copyright (c) 2019 befovy <befovy@gmail.com>
*
* This file is part of ijkPlayer.
*
* ijkPlayer is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* ijkPlayer is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with ijkPlayer; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/


#include "ijkplayer_desktop.h"

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

void  demo_event_cb (void *userdata, int what, int arg1, int arg2, void *extra)
{
    printf("demo event cb what %5d:(%5d %5d)\n", what, arg1, arg2);
}

void demo_overlay_cb (void *userdata, IjkFFOverlay* overlay)
{
    printf("demo overlay cb what %p:(%5d %5d)\n", overlay, overlay->h, overlay->w);
}


int main(int argc, char *argv[])
{
    IjkFFMediaPlayer *fp = ijkff_create();
    ijkff_set_data_source(fp, "D:\\demo.MKV");
    ijkff_prepare_async(fp);
    ijkff_start(fp);

    ijkff_set_event_cb(fp, NULL, demo_event_cb);
    ijkff_set_overlay_cb(fp, NULL, demo_overlay_cb);

    int x = 0;
    while(x < 10) {
        x ++;
        Sleep(1000);
    }
    ijkff_stop(fp);
    ijkff_shutdown(fp);
    system("pause");
    return 0;
}