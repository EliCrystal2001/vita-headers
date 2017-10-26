/**
 * \kernelgroup{SceDisplay}
 * \usage{psp2kern/display.h,SceDisplayForDriver_stub}
 */


#ifndef _PSP2_KERNEL_DISPLAY_H_
#define _PSP2_KERNEL_DISPLAY_H_

#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SceDisplayErrorCode {
	SCE_DISPLAY_ERROR_OK                    = 0,
	SCE_DISPLAY_ERROR_INVALID_HEAD          = 0x80290000,
	SCE_DISPLAY_ERROR_INVALID_VALUE         = 0x80290001,
	SCE_DISPLAY_ERROR_INVALID_ADDR          = 0x80290002,
	SCE_DISPLAY_ERROR_INVALID_PIXELFORMAT   = 0x80290003,
	SCE_DISPLAY_ERROR_INVALID_PITCH         = 0x80290004,
	SCE_DISPLAY_ERROR_INVALID_RESOLUTION    = 0x80290005,
	SCE_DISPLAY_ERROR_INVALID_UPDATETIMING  = 0x80290006,
	SCE_DISPLAY_ERROR_NO_FRAME_BUFFER       = 0x80290007,
	SCE_DISPLAY_ERROR_NO_PIXEL_DATA         = 0x80290008
} SceDisplayErrorCode;

typedef enum SceDisplayPixelFormat {
	SCE_DISPLAY_PIXELFORMAT_A8B8G8R8 = 0x00000000U
} SceDisplayPixelFormat;

typedef enum SceDisplaySetBufSync {
	/** Buffer change effective immediately */
	SCE_DISPLAY_SETBUF_IMMEDIATE = 0,
	/** Buffer change effective next frame */
	SCE_DISPLAY_SETBUF_NEXTFRAME = 1
} SceDisplaySetBufSync;

/**
 * Structure used with ::ksceDisplaySetFrameBuf to set/update framebuffer.
 * Original screen resolution is 960x544, but the following resolutions
 * can also be supplied as width and height :
 * 480x272, 640x368, 720x408
 *
 * @note - This structure is returned by ::ksceDisplayGetFrameBuf
*/
typedef struct SceDisplayFrameBuf {
	SceSize size;               //!< sizeof(SceDisplayFrameBuf)
	void *base;                 //!< Pointer to framebuffer
	unsigned int pitch;         //!< pitch pixels
	unsigned int pixelformat;   //!< pixel format (one of ::SceDisplayPixelFormat)
	unsigned int width;         //!< framebuffer width
	unsigned int height;        //!< framebuffer height
} SceDisplayFrameBuf;

/**
 * Set/Update framebuffer parameters
 *
 * @param[in] pParam - Pointer to a ::SceDisplayFrameBuf structure.
 * @param[in] sync - One of ::DisplaySetBufSync
 *
 * @return 0 on success, < 0 on error.
 * @note - If NULL is provided as pParam pointer, output is blacked out.
*/
int ksceDisplaySetFrameBuf(const SceDisplayFrameBuf *pParam, int sync);

/**
 * Get current framebuffer parameters
 *
 * @param[out] pParam - Pointer to a ::SceDisplayFrameBuf structure
 * which will receive framebuffer parameters.
 *
 * @param[in] sync - One of ::DisplaySetBufSync
 *
 * @return 0 on success, < 0 on error.
*/
int ksceDisplayGetFrameBuf(SceDisplayFrameBuf *pParam, int sync);

/**
 * Get current framebuffer dimensions
 *
 * @param[out] width - Framebuffer width
 * @param[out] height - Framebuffer height
 *
 * @return 0 on success, < 0 on error.
*/
int ksceDisplayGetFrameBufDimensions(int *width, int *height);

/**
 * Number of vertical blank pulses up to now for display
 *
 * @param[in] display - Display index
 */
int ksceDisplayGetVcountForDisplay(int display);

/**
 * Wait for vertical blank start
 */
int ksceDisplayWaitVblankStart(void);

/**
 * Wait for vertical blank start for display
 *
 * @param[in] display - Display index
 */
int ksceDisplayWaitVblankStartForDisplay(int display);

/**
 * Wait for vertical blank start with callback
 */
int ksceDisplayWaitVblankStartCB(void);

/**
 * Wait for vertical blank start with callback for display
 *
 * @param[in] display - Display index
 */
int ksceDisplayWaitVblankStartCBForDisplay(int display);

/**
 * Wait for vertical blank start after specified number of vertical periods
 *
 * @param[in] vcount - Number of vertical periods before waiting for vertical blank start
 */
int ksceDisplayWaitVblankStartMulti(unsigned int vcount);

/**
 * Wait for vertical blank start after specified number of vertical periods for display
 *
 * @param[in] display - Display index
 * @param[in] vcount - Number of vertical periods before waiting for vertical blank start
 */
int ksceDisplayWaitVblankStartMultiForDisplay(int display, unsigned int vcount);

/**
 * Wait for vertical blank start with callback after specified number of vertical periods
 *
 * @param[in] vcount - Number of vertical periods before waiting for vertical blank start
 */
int ksceDisplayWaitVblankStartMultiCB(unsigned int vcount);

/**
 * Wait for vertical blank start with callback after specified number of vertical periods for display
 *
 * @param[in] display - Display index
 * @param[in] vcount - Number of vertical periods before waiting for vertical blank start
 */
int ksceDisplayWaitVblankStartMultiCBForDisplay(int display, unsigned int vcount);

/**
 * Wait for vertical blank start since last update of framebuffer
 */
int ksceDisplayWaitSetFrameBuf(void);

/**
 * Wait for vertical blank start with callback since last update of framebuffer
 */
int ksceDisplayWaitSetFrameBufCB(void);

/**
 * Wait for vertical blank start after specified number of vertical periods
 * since last update of framebuffer.
 *
 * @param[in] vcount - Number of vertical periods before waiting for vertical blank start
 */
int ksceDisplayWaitSetFrameBufMulti(unsigned int vcount);

/**
 * Wait for vertical blank start with callback after specified number of vertical periods
 * since last update of framebuffer.
 *
 * @param[in] vcount - Number of vertical periods before waiting for vertical blank start
 */
int ksceDisplayWaitSetFrameBufMultiCB(unsigned int vcount);

/**
 * Register callback to be used at each vertical blank start
 *
 * @param[in] uid - Callback UID
 */
int ksceDisplayRegisterVblankStartCallback(SceUID uid);

/**
 * Register callback to be used at each vertical blank start for a display
 *
 * @param[in] display - Display index
 * @param[in] uid - Callback UID
 */
int ksceDisplayRegisterVblankStartCallbackForDisplay(int display, SceUID uid);

/**
 * Unregister callback used at each vertical blank start
 *
 * @param[in] uid - Callback UID
 */
int ksceDisplayUnregisterVblankStartCallback(SceUID uid);

/**
 * Unregister callback used at each vertical blank start for a display
 *
 * @param[in] display - Display index
 * @param[in] uid - Callback UID
 */
int ksceDisplayUnregisterVblankStartCallbackForDisplay(int display, SceUID uid);

/**
 * Register callback to be used when the framebuffer changes
 *
 * @param[in] uid - Callback UID
 */
int ksceDisplayRegisterFrameBufCallback(SceUID uid);

/**
 * Register callback to be used when the framebuffer changes for a display
 *
 * @param[in] display - Display index
 * @param[in] uid - Callback UID
 */
int ksceDisplayRegisterFrameBufCallbackForDisplay(int display, SceUID uid);

/**
 * Enable/disable color inversion for a display.
 *
 * @param[in] display - Display index
 * @param[in] enable - Enable/disable color inversion
 */
int ksceDisplaySetInvertColors(int display, int enable);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_DISPLAY_H_ */

