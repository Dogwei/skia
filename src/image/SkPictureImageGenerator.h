/*
 * Copyright 2023 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPictureImageGenerator_DEFINED
#define SkPictureImageGenerator_DEFINED

#include "include/core/SkImageGenerator.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPicture.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkSurfaceProps.h"
#include "src/base/SkTLazy.h"

#include <cstddef>

struct SkImageInfo;

class SkPictureImageGenerator : public SkImageGenerator {
public:
    SkPictureImageGenerator(const SkImageInfo&, sk_sp<SkPicture>, const SkMatrix*,
                            const SkPaint*, const SkSurfaceProps&);

protected:
    bool onGetPixels(const SkImageInfo&, void* pixels, size_t rowBytes, const Options&) override;

#if defined(SK_GRAPHITE)
    sk_sp<SkImage> onMakeTextureImage(skgpu::graphite::Recorder*,
                                      const SkImageInfo&,
                                      skgpu::Mipmapped) override;
#endif

private:
    sk_sp<SkPicture> fPicture;
    SkMatrix         fMatrix;
    SkTLazy<SkPaint> fPaint;
    SkSurfaceProps   fProps;

    friend class SkImage_Picture;
};

#endif
