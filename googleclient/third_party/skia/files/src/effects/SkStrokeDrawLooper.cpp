// Copyright 2008 Google Inc. All Rights Reserved.
// Author: scroggo@google.com (Leon Scroggins)

// This file contains the implementation of the SkStrokeDrawLooper class.

#include "SkStrokeDrawLooper.h"
#include "SkCanvas.h"

SkStrokeDrawLooper::SkStrokeDrawLooper(SkScalar radius, SkColor color)
    : fColor(color), fRadius(radius) {
}

void SkStrokeDrawLooper::init(SkCanvas* canvas, SkPaint* paint) {
  fState = kBeforeEdge;
  fCanvas = canvas;
  fPaint = paint;
}

bool SkStrokeDrawLooper::next() {
  switch (fState) {
    case kBeforeEdge:
      fSavedStyle = fPaint->getStyle();
      fSavedStrokeWidth = fPaint->getStrokeWidth();
      fSavedColor = fPaint->getColor();
      fPaint->setColor(fColor);
      fPaint->setStrokeWidth(fRadius);
      fPaint->setStyle(SkPaint::kStroke_Style);
      fState = kAfterEdge;
      return true;
    case kAfterEdge:
      fPaint->setColor(fSavedColor);
      fPaint->setStrokeWidth(fSavedStrokeWidth);
      fPaint->setStyle(fSavedStyle);
      fState = kDone;
      return true;
    default:
      SkASSERT(kDone == fState);
      return false;
  }
}

void SkStrokeDrawLooper::restore() {
  if (fState == kAfterEdge) {
    fPaint->setColor(fSavedColor);
    fPaint->setStrokeWidth(fSavedStrokeWidth);
    fPaint->setStyle(fSavedStyle);
    fState = kDone;
  }
}

void SkStrokeDrawLooper::flatten(SkFlattenableWriteBuffer& buffer) {
  buffer.writeScalar(fRadius);
  buffer.write32(fColor);
}

SkStrokeDrawLooper::SkStrokeDrawLooper(SkFlattenableReadBuffer& buffer) {
  fRadius = buffer.readScalar();
  fColor = buffer.readU32();
}
