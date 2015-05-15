// Copyright 2008 Google Inc. All Rights Reserved.
// Author: scroggo@google.com (Leon Scroggins)

// This file contains the declaration of the StrokeLooper class.

#ifndef SkSrokeDrawLooper_DEFINED
#define SkSrokeDrawLooper_DEFINED

#include "SkDrawLooper.h"
#include "SkColor.h"
#include "SkPaint.h"

class SkCanvas;

/** \class SkStrokeDrawLooper This class draws an outline of the
*   object, and then draws the original object in its original
*   position.
*/
class SkStrokeDrawLooper : public SkDrawLooper {
 public:
  SkStrokeDrawLooper(SkScalar radius, SkColor color);
  virtual ~SkStrokeDrawLooper() {}
  virtual void init(SkCanvas* canvas, SkPaint* paint);
  virtual bool next();
  virtual void restore();

 private:
  SkCanvas* fCanvas;
  SkPaint* fPaint;
  SkPaint::Style fSavedStyle;
  SkScalar fSavedStrokeWidth;
  SkColor fSavedColor;
  SkScalar fRadius;
  SkColor fColor;
  enum State {
    kBeforeEdge,
    kAfterEdge,
    kDone
  };
  State   fState;
  static SkFlattenable* CreateProc(SkFlattenableReadBuffer& buffer) {
        return SkNEW_ARGS(SkStrokeDrawLooper, (buffer)); }
 protected:
  virtual Factory getFactory() { return CreateProc; }
  void flatten(SkFlattenableWriteBuffer& buffer);
  SkStrokeDrawLooper(SkFlattenableReadBuffer& buffer);
};

#endif  // SkSrokeDrawLooper_DEFINED
