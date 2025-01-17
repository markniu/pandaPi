/***************************************************************************
 * ARM Stack Unwinder, Michael.McTernan.2001@cs.bris.ac.uk
 * Updated, adapted and several bug fixes on 2018 by Eduardo José Tagle
 *
 * This program is PUBLIC DOMAIN.
 * This means that there is no copyright and anyone is able to take a copy
 * for free and use it as they wish, with or without modifications, and in
 * any context, commercially or otherwise. The only limitation is that I
 * don't guarantee that the software is fit for any purpose or accept any
 * liability for its use or misuse - this software is without warranty.
 ***************************************************************************
 * File Description: Implementation of the interface into the ARM unwinder.
 **************************************************************************/

#if 0// defined(__arm__) || defined(__thumb__)//  PANDAPI

#define MODULE_NAME "UNWINDER"

#include <stdio.h>
#include <string.h>
#include "unwinder.h"
#include "unwarm.h"
#include "unwarmbytab.h"

/* These symbols point to the unwind index and should be provide by the linker script */
extern "C" const UnwTabEntry __exidx_start[];
extern "C" const UnwTabEntry __exidx_end[];

// Detect if unwind information is present or not
static int HasUnwindTableInfo() {
  // > 16 because there are default entries we can't suppress
  return ((char*)(&__exidx_end) - (char*)(&__exidx_start)) > 16 ? 1 : 0;
}

UnwResult UnwindStart(UnwindFrame* frame, const UnwindCallbacks *cb, void *data) {
  if (HasUnwindTableInfo()) {
    /* We have unwind information tables */
    return UnwindByTableStart(frame, cb, data);
  }
  else {

    /* We don't have unwind information tables */
    UnwState state;

    /* Initialize the unwinding state */
    UnwInitState(&state, cb, data, frame->pc, frame->sp);

    /* Check the Thumb bit */
    return (frame->pc & 0x1) ? UnwStartThumb(&state) : UnwStartArm(&state);
  }
}
#endif
