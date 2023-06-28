//
// Created by caiiiycuk on 03.04.2020.
//
#ifndef __AVI_H__
#define __AVI_H__

#ifdef __cplusplus
extern "C" {
#endif
#ifndef INT64_C
#	define INT64_C(c) (c ## LL)
#	define UINT64_C(c) (c ## ULL)
#endif

#ifdef __cplusplus
}
#endif

#define AVI_END_VIDEO		0x00010000
#define AVI_END_SOUND		0x00020000

struct AVIFile : XListElement
{
    ~AVIFile();
    AVIFile(void);
    AVIFile(char *aviname, int flags, int channel);
    int open(char *aviname, int flags, int channel);
    void draw(void);
    void close(void);
};

int AVIopen(char *filename, int flags, int channel, void **avi);
void AVIplay(void *avi,int x, int y);
void AVIstop(void *avi);
void AVIclose(void *avi);
int AVIwidth(void *avi);
int AVIheight(void *avi);
int AVIredraw(void *avi);
void AVIredraw(void *avi, int state);

void AVIPrepareFrame(void *avi);
void AVIDrawFrame(void *avi, int offsetX, int offsetY, int lineWidth, uint32_t* rgba, float bright = 1.0f);

#endif //__AVI_H__

