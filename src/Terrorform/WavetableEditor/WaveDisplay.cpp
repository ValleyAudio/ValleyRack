#include "WaveDisplay.hpp"

TFormEditorWaveDisplay::TFormEditorWaveDisplay() {
    offColor = nvgRGBA(0xAF, 0xAF, 0xAF, 0x6F);
    onColor = nvgRGBA(0xDF, 0x00, 0x00, 0xFF);
    bgColor = nvgRGBA(0xDF, 0x00, 0x00, 0x7F);

    selectedWave = 0;
    waveSliderPos = 0.f;
    normSliderPos = 0.f;
    numWaves = TFORM_MAX_NUM_WAVES;

    for (auto w = 0; w < TFORM_MAX_NUM_WAVES; ++w) {
        for (auto i = 0; i < TFORM_MAX_WAVELENGTH; ++i) {
            waveData[w][i] = 0.f;
        }
    }
}

void TFormEditorWaveDisplay::draw(const DrawArgs& args) {
    if (numWaves < 1) {
        return;
    }

    dX = dimetricProject(1.f, 0.f, 1.f).x;
    dY = dimetricProject(0.f, 1.f, 1.f).y - dimetricProject(1.f, -1.f, 0.f).y;
    dZ = 1.f / (numWaves - 1.f);
    mX = (box.size.x - 16) / dX;
    mY = box.size.y / dY * 0.8f;
    xOffset = 8 * dimetricProject(1.f, 0.f, 0.f).x;

    triPos = dimetricProject(1.f, 0.f, (1.f - normSliderPos * dZ));
    triPos = scalePoint(triPos);
    triPos.x -= 4.f;
    nvgBeginPath(args.vg);
    nvgMoveTo(args.vg, triPos.x, triPos.y);
    nvgLineTo(args.vg, triPos.x - 4.3301, triPos.y + 2.5);
    nvgLineTo(args.vg, triPos.x - 4.3301, triPos.y - 2.5);
    nvgLineTo(args.vg, triPos.x, triPos.y);
    nvgFillColor(args.vg, onColor);
    nvgFill(args.vg);

    for (int w = numWaves - 1; w >= 0; --w) {
        if (w == selectedWave) {
            drawWaveFilled(selectedWave, bgColor, args);
            drawWaveLine(selectedWave, onColor, args);
        }
        else {
            drawWaveLine(w, offColor, args);
        }
    }
    drawWaveBox(selectedWave, args);

    triPos = dimetricProject(0.f, 0.f, (1.f - normSliderPos * dZ));
    triPos = scalePoint(triPos);
    triPos.x += 4.f;
    nvgBeginPath(args.vg);
    nvgMoveTo(args.vg, triPos.x, triPos.y);
    nvgLineTo(args.vg, triPos.x + 4.3301, triPos.y - 2.5);
    nvgLineTo(args.vg, triPos.x + 4.3301, triPos.y + 2.5);
    nvgLineTo(args.vg, triPos.x, triPos.y);
    nvgFillColor(args.vg, onColor);
    nvgFill(args.vg);

    Widget::draw(args);
}

void TFormEditorWaveDisplay::drawWaveLine(int w, const NVGcolor& color, const DrawArgs& args) {
    float z = numWaves > 1 ? (1.f - w * dZ) : 0.5f;

    nvgBeginPath(args.vg);
    nvgStrokeWidth(args.vg, 1.0);
    nvgStrokeColor(args.vg, color);
    nvgLineCap(args.vg, NVG_ROUND);
    nvgLineJoin(args.vg, NVG_ROUND);

    pW = dimetricProject(1.f, 0.f, z);
    pW = scalePoint(pW);
    nvgMoveTo(args.vg, pW.x, pW.y);
    for (int i = 0; i < TFORM_WAVELENGTH_CAP; ++i) {
        pW = dimetricProject(1.f - (float) i / (TFORM_WAVELENGTH_CAP - 1.f), -waveData[w][i] * 0.75f, z);
        pW = scalePoint(pW);
        nvgLineTo(args.vg, pW.x, pW.y);
    }

    pW = dimetricProject(0.f, 0.f, z);
    pW = scalePoint(pW);
    nvgLineTo(args.vg, pW.x, pW.y);
    nvgStroke(args.vg);
    nvgLineCap(args.vg, NVG_BUTT);
    nvgLineJoin(args.vg, NVG_MITER);
}

void TFormEditorWaveDisplay::drawWaveFilled(int w, const NVGcolor& color, const DrawArgs& args) {
    float z = numWaves > 1 ? (1.f - w * dZ) : 0.5f;

    nvgBeginPath(args.vg);
    nvgFillColor(args.vg, color);
    pW = dimetricProject(1.f, 0.f, z);
    pW = scalePoint(pW);

    nvgMoveTo(args.vg, pW.x, pW.y);
    for (int i = 0; i < TFORM_WAVELENGTH_CAP; ++i) {
        pW = dimetricProject(1.f - (float) i / (TFORM_WAVELENGTH_CAP - 1.f), -waveData[w][i] * 0.75f, z);
        pW = scalePoint(pW);
        nvgLineTo(args.vg, pW.x, pW.y);
    }

    pW = dimetricProject(0.f, 0.f, z);
    pW = scalePoint(pW);
    nvgLineTo(args.vg, pW.x, pW.y);
    nvgFill(args.vg);
}

void TFormEditorWaveDisplay::drawWaveBox(int w, const DrawArgs& args) {
    float startX = 3;
    float endX = box.size.x;
    float xScale = (endX - startX) / ((float)TFORM_WAVELENGTH_CAP - 1.f);
    float yOffset =  box.size.y - 18;
    float yScale = 14.f;

    float boxWidth = box.size.x;
    float boxHeight = 30.f;
    float boxX = 0;
    float boxY = box.size.y - boxHeight - 3.f;

    // Waveform fill
    nvgBeginPath(args.vg);
    nvgMoveTo(args.vg, startX, yOffset);
    for (int i = 0; i < TFORM_WAVELENGTH_CAP; ++i) {
        nvgLineTo(args.vg, startX + (float) i * xScale, -waveData[w][i] * yScale + yOffset);
    }
    nvgLineTo(args.vg, endX, yOffset);
    nvgFillColor(args.vg, bgColor);
    nvgFill(args.vg);
    nvgClosePath(args.vg);

    // Waveform stroke
    nvgBeginPath(args.vg);
    nvgLineCap(args.vg, NVG_ROUND);
    nvgLineJoin(args.vg, NVG_ROUND);
    nvgMoveTo(args.vg, startX, yOffset);
    for (int i = 0; i < TFORM_WAVELENGTH_CAP; ++i) {
        nvgLineTo(args.vg, startX + (float) i * xScale, -waveData[w][i] * yScale + yOffset);
    }
    nvgLineTo(args.vg, endX, yOffset);
    nvgStrokeWidth(args.vg, 1.0);
    nvgStrokeColor(args.vg, onColor);
    nvgStroke(args.vg);
    nvgLineCap(args.vg, NVG_BUTT);
    nvgLineJoin(args.vg, NVG_MITER);

    // Waveform box outline
    nvgBeginPath(args.vg);
    nvgRect(args.vg, boxX, boxY, boxWidth, boxHeight);
    nvgStrokeColor(args.vg, nvgRGBA(0xAF, 0xAF, 0xAF, 0x6F));
    nvgStroke(args.vg);
}

void TFormEditorWaveDisplay::moveSliderPos(float sliderDelta) {
    waveSliderPos -= sliderDelta;
    if(waveSliderPos < 0.f) {
        waveSliderPos = 0.f;
    }
    if(waveSliderPos > box.size.y) {
        waveSliderPos = box.size.y;
    }
    normSliderPos = (waveSliderPos / box.size.y) * (float)(numWaves - 1);
    selectedWave = (int) (normSliderPos + 0.5f);
}

Vec TFormEditorWaveDisplay::dimetricProject(float x, float y, float z) const {
    const float cos7 = 0.992546;
    const float cos42 = 0.743145;
    const float sin7 = 0.121869;
    const float sin42 = 0.669131;
    return Vec(x * cos7 + 0.5 * (z * 2.f * cos42), y + (z * sin42) - x * sin7);
}

Vec TFormEditorWaveDisplay::scalePoint(const Vec& p) const {
    Vec newP = p;
    newP.x *= mX;
    newP.y += 1.2127;
    newP.y *= mY;
    newP.x = box.size.x - newP.x - xOffset;
    return newP;
}