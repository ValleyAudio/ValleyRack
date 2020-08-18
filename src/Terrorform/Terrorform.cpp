#include "Terrorform.hpp"

Terrorform::Terrorform() {
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(Terrorform::OCTAVE_PARAM, -3.0, 3.0, 0.0, "Octave");
    configParam(Terrorform::COARSE_PARAM, -1.0, 1.0, 0.0, "Coarse Tune");
    configParam(Terrorform::FINE_PARAM, -0.041666, 0.041666, 0.0, "Fine Tune");
    configParam(Terrorform::VOCT_1_CV_PARAM, -1.0, 1.0, 0.0, "VOct 1 Atten.");
    configParam(Terrorform::VOCT_2_CV_PARAM, -1.0, 1.0, 0.0, "VOct 2 Atten.");

    configParam(Terrorform::BANK_PARAM, 0.0, NUM_TERRORFORM_WAVETABLES - 1.f, 0.0, "Bank");
    configParam(Terrorform::WAVE_PARAM, 0.0, 1.0, 0.0, "Wave");
    configParam(Terrorform::BANK_CV_1_PARAM, -1.0, 1.0, 0.0, "Bank CV Atten. 1");
    configParam(Terrorform::BANK_CV_2_PARAM, -1.0, 1.0, 0.0, "Bank CV Atten. 2");
    configParam(Terrorform::WAVE_CV_1_PARAM, -1.0, 1.0, 0.0, "Wave CV Atten. 1");
    configParam(Terrorform::WAVE_CV_2_PARAM, -1.0, 1.0, 0.0, "Wave CV Atten. 2");

    configParam(Terrorform::SHAPE_TYPE_PARAM, 0.0, Shaper::Modes::NUM_MODES - 1.0, 0.0, "Shape Type");
    configParam(Terrorform::SHAPE_DEPTH_PARAM, 0.0, 1.0, 0.0, "Shape Depth");
    configParam(Terrorform::SHAPE_TYPE_CV_1_PARAM, -1.0, 1.0, 0.0, "Shape Type CV Atten. 1");
    configParam(Terrorform::SHAPE_TYPE_CV_2_PARAM, -1.0, 1.0, 0.0, "Shape Type CV Atten. 2");
    configParam(Terrorform::SHAPE_DEPTH_CV_1_PARAM, -1.0, 1.0, 0.0, "Shape Depth CV Atten. 1");
    configParam(Terrorform::SHAPE_DEPTH_CV_2_PARAM, -1.0, 1.0, 0.0, "Shape Depth CV Atten. 2");

    configParam(Terrorform::ENHANCE_TYPE_PARAM, 0.0, VecEnhancer::VecEnhancerModes::NUM_MODES - 1.f, 0.0, "Enhance Type");
    configParam(Terrorform::ENHANCE_DEPTH_PARAM, 0.0, 1.0, 0.0, "Enhance Depth");
    configParam(Terrorform::ENHANCE_TYPE_CV_1_PARAM, -1.0, 1.0, 0.0, "Enhance Type CV Atten. 1");
    configParam(Terrorform::ENHANCE_TYPE_CV_2_PARAM, -1.0, 1.0, 0.0, "Enhance Type CV Atten. 2");
    configParam(Terrorform::ENHANCE_DEPTH_CV_1_PARAM, -1.0, 1.0, 0.0, "Enhance Depth CV Atten. 1");
    configParam(Terrorform::ENHANCE_DEPTH_CV_2_PARAM, -1.0, 1.0, 0.0, "Enhance Depth CV Atten. 2");

    configParam(Terrorform::LPG_ATTACK_PARAM, 0.0, 1.0, 0.0, "Lowpass Gate Attack");
    configParam(Terrorform::LPG_DECAY_PARAM, 0.0, 1.0, 0.5, "Lowpass Gate Decay");
    configParam(Terrorform::LPG_ATTACK_CV_1_PARAM, -1.0, 1.0, 0.0, "LPG Attack CV1 Atten.");
    configParam(Terrorform::LPG_ATTACK_CV_2_PARAM, -1.0, 1.0, 0.0, "LPG Attack CV2 Atten.");
    configParam(Terrorform::LPG_DECAY_CV_1_PARAM, -1.0, 1.0, 0.0, "LPG Decay CV1 Atten.");
    configParam(Terrorform::LPG_DECAY_CV_2_PARAM, -1.0, 1.0, 0.0, "LPG Decay CV2 Atten.");

    configParam(Terrorform::SKEW_PARAM, 0.0, 1.0, 0.0, "Phasor Feedback Skew");
    configParam(Terrorform::SUB_OSC_LEVEL_PARAM, 0.0, 1.0, 0.0, "Sub Oscillator Main Level");
    configParam(Terrorform::SUB_OSC_WAVE_PARAM, 0.0, 1.0, 0.0, "Sub Oscillator Wave");

    configParam(Terrorform::LPG_MODE_SWITCH_PARAM, 0.0, 1.0, 0.0, "LPG Mode (Hold to toggle)");
    configParam(Terrorform::LPG_LONG_TIME_SWITCH_PARAM, 0.0, 1.0, 0.0, "LPG Time Range");
    configParam(Terrorform::LPG_VELOCITY_SWITCH_PARAM, 0.0, 1.0, 0.0, "LPG Velocity Sensitivity");
    configParam(Terrorform::LPG_TRIGGER_SWITCH_PARAM, 0.0, 1.0, 0.0, "LPG Trigger Mode");

    configParam(Terrorform::FM_A1_ATTEN_PARAM, 0.0, 1.0, 0.0, "FM A1 Level");
    configParam(Terrorform::FM_A2_ATTEN_PARAM, 0.0, 1.0, 0.0, "FM A2 Level");
    configParam(Terrorform::FM_B1_ATTEN_PARAM, 0.0, 1.0, 0.0, "FM B1 Level");
    configParam(Terrorform::FM_B2_ATTEN_PARAM, 0.0, 1.0, 0.0, "FM B2 Level");
    configParam(Terrorform::FM_A_VCA_ATTEN_PARAM, 0.0, 1.0, 0.0, "FM A VCA Gain");
    configParam(Terrorform::FM_B_VCA_ATTEN_PARAM, 0.0, 1.0, 0.0, "FM B VCA Gain");

    configParam(Terrorform::WEAK_SYNC_1_SWITCH_PARAM, 0.0, 1.0, 0.0, "Weak Sync 1");
    configParam(Terrorform::WEAK_SYNC_2_SWITCH_PARAM, 0.0, 1.0, 0.0, "Weak Sync 2");

    configParam(Terrorform::USER_BANK_SWITCH_PARAM, 0.0, 1.0, 0.0, "User Waves");
    configParam(Terrorform::TRUE_FM_SWITCH_PARAM, 0.0, 1.0, 0.0, "FM Mode");
    configParam(Terrorform::SWAP_SWITCH_PARAM, 0.0, 1.0, 0.0, "Enhancer & LPG order");
    configParam(Terrorform::LFO_SWITCH_PARAM, 0.0, 1.0, 0.0, "LFO Mode");
    configParam(Terrorform::ZERO_SWITCH_PARAM, 0.0, 1.0, 0.0, "Zero Frequency Mode");
    configParam(Terrorform::POST_PM_SHAPE_PARAM, 0.0, 1.0, 0.0, "Phasor shaping");
    configParam(Terrorform::DISPLAY_CV_SWITCH_PARAM, 0.0, 1.0, 0.0, "Display CV Offset");

    for(int i = 0; i < kMaxNumGroups; ++i) {
        osc[i].setWavebank(wavetables[0], wavetable_sizes[0], wavetable_lengths[0][0]);
        osc[i].setScanPosition(0.f);
        osc[i].setSampleRate(APP->engine->getSampleRate());
        osc[i].setShape(0.0);
        osc[i].setShapeMethod(0);
        osc[i].enableSync(true);
        mainOutDCBlock[i].setSampleRate(APP->engine->getSampleRate());
        mainOutDCBlock[i].setSampleRate(APP->engine->getSampleRate());
        enhancerOutDCBlock[i].setSampleRate(APP->engine->getSampleRate());
        rawOutDCBlock[i].setCutoffFreq(2.f);
        rawOutDCBlock[i].setCutoffFreq(2.f);
        enhancerOutDCBlock[i].setCutoffFreq(2.f);
    }
    bank = 0;
    shapeType = 0;

    rootWave = 0.f;
    numWavesInTable = 1.f;
    rootShapeDepth = 0.f;
    rootEnhanceDepth = 0.f;

    __zeros = _mm_set1_ps(0.f);
    __ones = _mm_set1_ps(1.f);
    __negOnes = _mm_set1_ps(-1.f);
    __twos = _mm_set1_ps(2.f);
    __negTwos = _mm_set1_ps(-2.f);
    __fives = _mm_set1_ps(5.f);
    __negFives = _mm_set1_ps(-5.f);
    __tens = _mm_set1_ps(10.f);
    __tenths = _mm_set1_ps(0.1f);
    __hundredths = _mm_set1_ps(0.01f);
    __quarters = _mm_set1_ps(0.25f);

    __sync1 = __zeros;
    __sync2 = __zeros;
    __sync1Pls = __zeros;
    __sync2Pls = __zeros;
    __weakSync1Flag = __zeros;
    __weakSync2Flag = __zeros;
    __lpgVCAMode = __zeros;
    __lpgFilterMode = __zeros;

    freqs = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    waves = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    wavesCV = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    shapes = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    shapesCV = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    enhances = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    enhancesCV = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    attacks = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    decays = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);
    skew = (float*)aligned_alloc_16(sizeof(float) * kMaxNumGroups * 4);

    // Fill user wavetables
    for(auto bank = 0; bank < TFORM_MAX_BANKS; ++bank) {
        userWaveTableData[bank] = new float*[TFORM_MAX_NUM_WAVES];
        userWaveTableFilled[bank] = false;
        userWaveTableSizes[bank] = 1;
        userWaveTableNames.push_back("EMPTY_" + std::to_string(bank + 1));
        for(auto wave = 0; wave < TFORM_MAX_NUM_WAVES; ++wave) {
            userWaveTableData[bank][wave] = new float[TFORM_MAX_WAVELENGTH];
            for(auto i = 0; i < TFORM_MAX_WAVELENGTH; ++i) {
                userWaveTableData[bank][wave][i] = 0.f;
            }
        }
    }
    numUserWaveTables = 0;

    readFromUserWaves = false;
}

Terrorform::~Terrorform() {
    aligned_free_16(freqs);
    aligned_free_16(waves);
    aligned_free_16(wavesCV);
    aligned_free_16(shapes);
    aligned_free_16(shapesCV);
    aligned_free_16(enhances);
    aligned_free_16(enhancesCV);
    aligned_free_16(attacks);
    aligned_free_16(decays);
    aligned_free_16(skew);

    for(auto bank = 0; bank < TFORM_MAX_BANKS; ++bank) {
        for(auto wave = 0; wave < TFORM_MAX_NUM_WAVES; ++wave) {
            delete[] userWaveTableData[bank][wave];
        }
        delete[] userWaveTableData[bank];
    }
}

void Terrorform::process(const ProcessArgs &args) {
    ++counter;
    if(counter > 512) {
        //printf("SRate = %f, STime = %f\n", args.sampleRate, args.sampleTime);
        readFromUserWaves = params[USER_BANK_SWITCH_PARAM].getValue() > 0.5f;
        if (readFromUserWaves) {
            maxNumBanks = TFORM_MAX_BANKS;
        }
        else {
            maxNumBanks = NUM_TERRORFORM_WAVETABLES;
        }

        displayCV = params[DISPLAY_CV_SWITCH_PARAM].getValue() > 0.5f;

        rootBank = params[BANK_PARAM].getValue();
        bankCV = (inputs[BANK_INPUT_1].getVoltage() * params[BANK_CV_1_PARAM].getValue() * 0.1f)
               + (inputs[BANK_INPUT_2].getVoltage() * params[BANK_CV_2_PARAM].getValue() * 0.1f);
        bankCV *= (float)(maxNumBanks - 1);
        bank = bankCV + rootBank;
        bank = clamp(bank, 0.f, (float)(maxNumBanks - 1));
        bankI = (int)bank;
        bankDisplay = displayCV ? bank : rootBank;

        rootShapeType = params[SHAPE_TYPE_PARAM].getValue();
        shapeTypeCV = (inputs[SHAPE_TYPE_INPUT_1].getVoltage() * params[SHAPE_TYPE_CV_1_PARAM].getValue() * 0.1f)
                    + (inputs[SHAPE_TYPE_INPUT_2].getVoltage() * params[SHAPE_TYPE_CV_2_PARAM].getValue() * 0.1f);
        shapeTypeCV *= (Shaper::Modes::NUM_MODES - 1.f);
        shapeType = shapeTypeCV + rootShapeType;
        shapeType = clamp(shapeType, 0.f, Shaper::Modes::NUM_MODES - 1.f);
        shapeTypeI = (int)phasorShapeMap[(int)shapeType];
        shapeDisplay = displayCV ? shapeType : rootShapeType;

        postPMShapeEnabled = params[POST_PM_SHAPE_PARAM].getValue() > 0.f;

        rootEnhanceType = params[ENHANCE_TYPE_PARAM].getValue();
        enhanceTypeCV = (inputs[ENHANCE_TYPE_INPUT_1].getVoltage() * params[ENHANCE_TYPE_CV_1_PARAM].getValue() * 0.1f)
                      + (inputs[ENHANCE_TYPE_INPUT_2].getVoltage() * params[ENHANCE_TYPE_CV_2_PARAM].getValue() * 0.1f);
        enhanceTypeCV *= (float)(VecEnhancer::VecEnhancerModes::NUM_MODES - 1);
        enhanceType = enhanceTypeCV + rootEnhanceType;
        enhanceType = clamp(enhanceType, 0.f, (float)(VecEnhancer::VecEnhancerModes::NUM_MODES - 1));
        enhanceTypeI = (int)enhanceType;
        enhanceDisplay = displayCV ? enhanceType : rootEnhanceType;

        lfoModeEnabled = params[LFO_SWITCH_PARAM].getValue() > 0.f;

        for(auto c = 0; c < kMaxNumGroups; ++c) {
            lpg[c].mode = (VecLPG::Modes) lpgMode;
            if(readFromUserWaves) {
                lights[USER_BANK_LIGHT].value = 1.f;
                osc[c].setWavebank(userWaveTableData[bankI],
                                   userWaveTableSizes[bankI],
                                   TFORM_MAX_WAVELENGTH);
            }
            else {
                lights[USER_BANK_LIGHT].value = 0.f;
                osc[c].setWavebank(wavetables[bankI],
                                   wavetable_sizes[bankI],
                                   wavetable_lengths[bankI][0]);
            }
            osc[c].setShapeMethod(shapeTypeI);
            enhancer[c].setMode(enhanceTypeI);
            osc[c].setSyncMode(syncChoice);
            osc[c].setPMPostShape(postPMShapeEnabled);
            mainOutDCBlock[c].setCutoffFreq(lfoModeEnabled ? 0.f : 2.f);
            rawOutDCBlock[c].setCutoffFreq(lfoModeEnabled ? 0.f : 2.f);
        }

        numWavesInTable = osc[0].getNumwaves() - 1.f;
        __numWavesInTable = _mm_set1_ps(numWavesInTable);

        // LPG
        switch ((VecLPG::Modes) lpgMode) {
            case VecLPG::Modes::BYPASS_MODE :
                lights[LPG_RED_LIGHT].value = 0.f;
                lights[LPG_GREEN_LIGHT].value = 0.f;
                lights[LPG_BLUE_LIGHT].value = 0.f;
                break;
            case VecLPG::Modes::VCA_MODE :
                lights[LPG_RED_LIGHT].value = 1.f;
                lights[LPG_GREEN_LIGHT].value = 0.f;
                lights[LPG_BLUE_LIGHT].value = 0.f;
                break;
            case VecLPG::Modes::FILTER_MODE :
                lights[LPG_RED_LIGHT].value = 0.f;
                lights[LPG_GREEN_LIGHT].value = 1.f;
                lights[LPG_BLUE_LIGHT].value = 0.f;
                break;
            case VecLPG::Modes::BOTH_MODE :
                lights[LPG_RED_LIGHT].value = 0.f;
                lights[LPG_GREEN_LIGHT].value = 0.f;
                lights[LPG_BLUE_LIGHT].value = 1.f;
                break;
        }

        lpgLongTime = params[LPG_LONG_TIME_SWITCH_PARAM].getValue() > 0.f;
        lpgVelocitySensitive = params[LPG_VELOCITY_SWITCH_PARAM].getValue() > 0.f;
        lpgTriggerMode = params[LPG_TRIGGER_SWITCH_PARAM].getValue() > 0.f;

        lights[LPG_LONG_TIME_LIGHT].value = (lpgLongTime ? 1.f : 0.f) * (lpgMode == 0 ? 0.5f : 1.f);
        lights[LPG_VELOCITY_LIGHT].value = (lpgVelocitySensitive ? 1.f : 0.f) * (lpgMode == 0 ? 0.5f : 1.f);
        lights[LPG_TRIGGER_LIGHT].value = (lpgTriggerMode ? 1.f : 0.f) * (lpgMode == 0 ? 0.5f : 1.f);

        __lpgVelocitySensitiveFlag = lpgVelocitySensitive ? _mm_high_ps() : __zeros;

        // Other button lights
        lights[TRUE_FM_LIGHT].value = trueFMEnabled;
        lights[POST_PM_SHAPE_LIGHT].value = postPMShapeEnabled;
        lights[SWAP_LIGHT].value = params[SWAP_SWITCH_PARAM].getValue();
        lights[WEAK_SYNC_1_LIGHT].value = (float) weakSync1Enable;
        lights[WEAK_SYNC_2_LIGHT].value = (float) weakSync2Enable;
        lights[LFO_LIGHT].value = (float) lfoModeEnabled;
        lights[ZERO_LIGHT].value = (float) zeroFreqEnabled;
        lights[DISPLAY_CV_LIGHT].value = (float) displayCV;

        numActiveChannels = std::max(inputs[VOCT_1_INPUT].getChannels(),
                                     inputs[VOCT_2_INPUT].getChannels());
        numActiveChannels = numActiveChannels < 1 ? 1 : numActiveChannels;
        numActiveGroups = (int) std::ceil((float) numActiveChannels / 4.f);
        numActiveGroups = numActiveGroups < 1 ? 1 : numActiveGroups;

        sync1IsMono = inputs[SYNC_1_INPUT].isMonophonic();
        sync2IsMono = inputs[SYNC_2_INPUT].isMonophonic();
        fmA1IsMono = inputs[FM_A1_INPUT].isMonophonic();
        fmA2IsMono = inputs[FM_A2_INPUT].isMonophonic();
        fmB1IsMono = inputs[FM_B1_INPUT].isMonophonic();
        fmB2IsMono = inputs[FM_B2_INPUT].isMonophonic();
        fmAVCAIsMono = inputs[FM_A_VCA_INPUT].isMonophonic();
        fmBVCAIsMono = inputs[FM_B_VCA_INPUT].isMonophonic();
        fmAVCAIsConnected = inputs[FM_A_VCA_INPUT].isConnected();
        fmBVCAIsConnected = inputs[FM_B_VCA_INPUT].isConnected();

        skewParam = inputs[SKEW_INPUT].isConnected() ? 0.f : params[SKEW_PARAM].getValue() * 0.18f;
        skewCV = inputs[SKEW_INPUT].isConnected() ? params[SKEW_PARAM].getValue() : 0.f;

        counter = 0;
    }

    // Perc mode press / hold
    lpgButtonPressed = params[LPG_MODE_SWITCH_PARAM].getValue() > 0.5f;
    if (lpgButtonPressed) {
        if (lpgButtonTimer.time < 0.5f) {
            lpgButtonTimer.process(args.sampleTime);
        }

        if (lpgButtonTimer.time >= 0.5f && !lpgButtonHeldDown) {
            lpgButtonHeldDown = true;
            if (lpgMode > 0) {
                lpgMode = 0;
            }
            else {
                lpgMode = 1;
            }
        }
    }

    // Button has been released
    if (!lpgButtonPressed && lpgButtonPrevState) {
        if (!lpgButtonHeldDown && lpgMode != 0) {
            lpgMode++;
            lpgMode = lpgMode == 4 ? 1 : lpgMode;
        }
        lpgButtonHeldDown = false;
        lpgButtonTimer.reset();
    }
    lpgButtonPrevState = lpgButtonPressed;

    // Sync button logic
    weakSync1Enable = params[WEAK_SYNC_1_SWITCH_PARAM].getValue() > 0.5f;
    weakSync2Enable = params[WEAK_SYNC_2_SWITCH_PARAM].getValue() > 0.5f;
    __weakSync1Flag = weakSync1Enable ? _mm_high_ps() : __zeros;
    __weakSync2Flag = weakSync2Enable ? _mm_high_ps() : __zeros;

    // Misc button logic
    swapEnhancerAndLPG = params[SWAP_SWITCH_PARAM].getValue() > 0.f;
    trueFMSwitchValue = params[TRUE_FM_SWITCH_PARAM].getValue();
    trueFMEnabled = trueFMSwitchValue > 0.f;
    if (trueFMSwitchValue != prevTrueFMSwitchValue) {
        for (int i = 0; i < numActiveChannels; ++i) {
            osc[i].resetPhase();
        }
    }
    prevTrueFMSwitchValue = trueFMSwitchValue;

    if (!zeroFreqEnabled && params[ZERO_SWITCH_PARAM].getValue() > 0.f) {
        for (int i = 0; i < kMaxNumGroups; ++i) {
            osc[i].resetPhase();
        }
    }
    zeroFreqEnabled = params[ZERO_SWITCH_PARAM].getValue() > 0.f;

    // Pitch, wave, shape and ehancement CV
    rootPitch = (int) params[OCTAVE_PARAM].getValue();
    rootPitch += params[COARSE_PARAM].getValue();
    rootPitch += params[FINE_PARAM].getValue();
    rootWave = params[WAVE_PARAM].getValue();
    rootShapeDepth = params[SHAPE_DEPTH_PARAM].getValue();
    rootEnhanceDepth = params[ENHANCE_DEPTH_PARAM].getValue();
    attackParam = params[LPG_ATTACK_PARAM].getValue();
    decayParam = params[LPG_DECAY_PARAM].getValue();

    pitchCV1 = params[VOCT_1_CV_PARAM].getValue();
    pitchCV2 = params[VOCT_2_CV_PARAM].getValue();
    bankCV1 = params[BANK_CV_1_PARAM].getValue();
    bankCV2 = params[BANK_CV_2_PARAM].getValue();
    waveCV1 = params[WAVE_CV_1_PARAM].getValue();
    waveCV2 = params[WAVE_CV_2_PARAM].getValue();
    shapeDepthCV1 = params[SHAPE_DEPTH_CV_1_PARAM].getValue();
    shapeDepthCV2 = params[SHAPE_DEPTH_CV_2_PARAM].getValue();
    enhanceDepthCV1 = params[ENHANCE_DEPTH_CV_1_PARAM].getValue();
    enhanceDepthCV2 = params[ENHANCE_DEPTH_CV_2_PARAM].getValue();
    attackCV1Depth = params[LPG_ATTACK_CV_1_PARAM].getValue();
    attackCV2Depth = params[LPG_ATTACK_CV_2_PARAM].getValue();
    decayCV1Depth = params[LPG_DECAY_CV_1_PARAM].getValue();
    decayCV2Depth = params[LPG_DECAY_CV_2_PARAM].getValue();

    for(auto i = 0; i < numActiveChannels; ++i) {
        freqs[i] = freqLUT.getFrequency(inputs[VOCT_1_INPUT].getPolyVoltage(i) * pitchCV1 +
                                        inputs[VOCT_2_INPUT].getPolyVoltage(i) * pitchCV2 +
                                        rootPitch);
        wavesCV[i] = inputs[WAVE_INPUT_1].getPolyVoltage(i) * waveCV1 * 0.1f;
        wavesCV[i] += inputs[WAVE_INPUT_2].getPolyVoltage(i) * waveCV2 * 0.1f;
        waves[i] = (rootWave + wavesCV[i]) * numWavesInTable;

        // shapes[i] = rootShapeDepth;
        shapesCV[i] = inputs[SHAPE_DEPTH_INPUT_1].getPolyVoltage(i) * shapeDepthCV1 * 0.1f;
        shapesCV[i] += inputs[SHAPE_DEPTH_INPUT_2].getPolyVoltage(i) * shapeDepthCV2 * 0.1f;
        shapes[i] = rootShapeDepth + shapesCV[i];

        enhancesCV[i] = inputs[ENHANCE_DEPTH_INPUT_1].getPolyVoltage(i) * enhanceDepthCV1 * 0.1f;
        enhancesCV[i] += inputs[ENHANCE_DEPTH_INPUT_2].getPolyVoltage(i) * enhanceDepthCV2 * 0.1f;
        enhances[i] = rootEnhanceDepth + enhancesCV[i];

        attacks[i] = attackParam;
        attacks[i] += inputs[ATTACK_1_INPUT].getPolyVoltage(i) * attackCV1Depth * 0.1f;
        attacks[i] += inputs[ATTACK_2_INPUT].getPolyVoltage(i) * attackCV2Depth * 0.1f;

        decays[i] = decayParam;
        decays[i] += inputs[DECAY_1_INPUT].getPolyVoltage(i) * decayCV1Depth * 0.1f;
        decays[i] += inputs[DECAY_2_INPUT].getPolyVoltage(i) * decayCV2Depth * 0.1f;

        skew[i] = skewParam;
        skew[i] += inputs[SKEW_INPUT].getPolyVoltage(i) * skewCV * 0.018f;
    }

    // Pass amounts up to display
    waveAmountDisplay = rootWave;
    waveAmountDisplay += (displayCV ? wavesCV[0] : 0.f);

    shapeAmountDisplay = rootShapeDepth;
    shapeAmountDisplay += (displayCV ? shapesCV[0] : 0.f);

    enhanceAmountDisplay = rootEnhanceDepth;
    enhanceAmountDisplay += (displayCV ? enhancesCV[0] : 0.f);

    sync1 = inputs[SYNC_1_INPUT].getVoltages();
    sync2 = inputs[SYNC_2_INPUT].getVoltages();
    trigger1 = inputs[TRIGGER_1_INPUT].getVoltages();
    trigger2 = inputs[TRIGGER_2_INPUT].getVoltages();
    fmA1 = inputs[FM_A1_INPUT].getVoltages();
    fmA2 = inputs[FM_A2_INPUT].getVoltages();
    fmB1 = inputs[FM_B1_INPUT].getVoltages();
    fmB2 = inputs[FM_B2_INPUT].getVoltages();
    fmAVCA = inputs[FM_A_VCA_INPUT].getVoltages();
    fmBVCA = inputs[FM_B_VCA_INPUT].getVoltages();

    fmA1Level = params[FM_A1_ATTEN_PARAM].getValue() * 0.2f;
    fmA2Level = params[FM_A2_ATTEN_PARAM].getValue() * 0.2f;
    fmB1Level = params[FM_B1_ATTEN_PARAM].getValue() * 0.2f;
    fmB2Level = params[FM_B2_ATTEN_PARAM].getValue() * 0.2f;
    fmAVCACV = params[FM_A_VCA_ATTEN_PARAM].getValue() * 0.1f;
    fmBVCACV = params[FM_B_VCA_ATTEN_PARAM].getValue() * 0.1f;
    __fmA1Level = _mm_set1_ps(fmA1Level);
    __fmA2Level = _mm_set1_ps(fmA2Level);
    __fmB1Level = _mm_set1_ps(fmB1Level);
    __fmB2Level = _mm_set1_ps(fmB2Level);
    __fmAVCACV = _mm_set1_ps(fmAVCACV);
    __fmBVCACV = _mm_set1_ps(fmBVCACV);

    __attackParam = _mm_set1_ps(attackParam);
    __decayParam = _mm_set1_ps(decayParam);

    // Tick the oscillator
    int g = 0;
    for(auto c = 0; c < numActiveGroups; ++c) {
        g = c * 4;

        // Sync
        __sync1 = sync1IsMono ? _mm_set1_ps(sync1[0]) : _mm_load_ps(sync1 + g);
        __sync2 = sync2IsMono ? _mm_set1_ps(sync2[0]) : _mm_load_ps(sync2 + g);
        __sync1Pls = _mm_and_ps(_mm_cmple_ps(__prevSync1, __zeros), _mm_cmpgt_ps(__sync1, __zeros));
        __sync1Pls = _mm_and_ps(__ones, __sync1Pls);
        __sync2Pls = _mm_and_ps(_mm_cmple_ps(__prevSync2, __zeros), _mm_cmpgt_ps(__sync2, __zeros));
        __sync2Pls = _mm_and_ps(__ones, __sync2Pls);
        __quarterPhase = _mm_cmplt_ps(osc[c].getPhasor(), __quarters);
        __sync1Pls = _mm_switch_ps(__sync1Pls, _mm_and_ps(__sync1Pls, __quarterPhase), __weakSync1Flag);
        __sync2Pls = _mm_switch_ps(__sync2Pls, _mm_and_ps(__sync2Pls, __quarterPhase), __weakSync2Flag);
        __prevSync1 = __sync1;
        __prevSync2 = __sync2;
        osc[c].sync(_mm_add_ps(__sync1Pls, __sync2Pls));

        // LPG
        __trigger1 = _mm_load_ps(trigger1 + g);
        __trigger2 = _mm_load_ps(trigger2 + g);
        __trigger1 = _mm_mul_ps(__trigger1, __tenths);
        __trigger2 = _mm_mul_ps(__trigger2, __tenths);

        __trigger1 = _mm_switch_ps(_mm_and_ps(__ones, _mm_cmpgt_ps(__trigger1, __zeros)),
                                    __trigger1, __lpgVelocitySensitiveFlag);
        __trigger2 = _mm_switch_ps(_mm_and_ps(__ones, _mm_cmpgt_ps(__trigger2, __zeros)),
                                    __trigger2, __lpgVelocitySensitiveFlag);


        lpg[c].setAttack(_mm_load_ps(attacks + g), lpgLongTime);
        lpg[c].setDecay(_mm_load_ps(decays + g), lpgLongTime);
        lpg[c].setTriggerMode(lpgTriggerMode);

        // FM
        __fmA = fmA1IsMono ? _mm_set1_ps(fmA1[0]) : _mm_load_ps(fmA1 + g);
        __fmA = _mm_mul_ps(__fmA, __fmA1Level);
        __fmA = _mm_add_ps(__fmA, _mm_mul_ps(fmA2IsMono ? _mm_set1_ps(fmA2[0]) : _mm_load_ps(fmA2 + g), __fmA2Level));
        __fmAVCA = fmAVCAIsMono ? _mm_set1_ps(fmAVCA[0]) : _mm_load_ps(fmAVCA + g);
        __fmAVCA = _mm_mul_ps(__fmAVCA, __fmAVCACV);
        __fmAVCA = fmAVCAIsConnected ? __fmAVCA : __ones;
        __fmA = _mm_mul_ps(__fmA, __fmAVCA);

        __fmB = fmB1IsMono ? _mm_set1_ps(fmB1[0]) : _mm_load_ps(fmB1 + g);
        __fmB = _mm_mul_ps(__fmB, __fmB1Level);
        __fmB = _mm_add_ps(__fmB, _mm_mul_ps(fmB2IsMono ? _mm_set1_ps(fmB2[0]) : _mm_load_ps(fmB2 + g), __fmB2Level));
        __fmBVCA = fmBVCAIsMono ? _mm_set1_ps(fmBVCA[0]) : _mm_load_ps(fmBVCA + g);
        __fmBVCA = _mm_mul_ps(__fmBVCA, __fmBVCACV);
        __fmBVCA = fmBVCAIsConnected ? __fmBVCA : __ones;
        __fmB = _mm_mul_ps(__fmB, __fmBVCA);

        __fmSum = _mm_add_ps(__fmA, __fmB);
        __freq = _mm_load_ps(freqs + g);
        __freq = _mm_mul_ps(__freq, (lfoModeEnabled ? __hundredths : __ones));
        __freq = _mm_mul_ps(__freq, (zeroFreqEnabled ? __zeros : __ones));
        __freq = _mm_add_ps(__freq, (trueFMEnabled ? _mm_mul_ps(__fmSum, _mm_set1_ps(1000.f)) : __zeros));
        osc[c].__inputPhase = trueFMEnabled ? __zeros : __fmSum;
        osc[c].__inputPhase = _mm_add_ps(osc[c].__inputPhase, _mm_mul_ps(osc[c].getOutput(), _mm_load_ps(skew + g)));

        __wave = _mm_load_ps(waves + g);
        __shape = _mm_load_ps(shapes + g);
        __enhance = _mm_load_ps(enhances + g);

        __wave = _mm_clamp_ps(__wave, __zeros, __numWavesInTable);
        __shape = _mm_clamp_ps(__shape, __zeros, __ones);
        __enhance = _mm_clamp_ps(__enhance, __zeros, __ones);

        osc[c].setFrequency(__freq);
        osc[c].mm_setScanPosition(__wave);
        osc[c].setShape(__shape);

        osc[c].tick();

        subOsc[c].setWave(_mm_set1_ps(params[SUB_OSC_WAVE_PARAM].getValue()));
        __subOscOut = subOsc[c].process(osc[c].getOutput(), osc[c].getPhasor(), osc[c].getEOCPulse(), osc[c].getStepSize(), osc[c].getDirection());
        __phasorOutput[c] = osc[c].getPhasor();
        __phasorOutput[c] = _mm_add_ps(_mm_mul_ps(__phasorOutput[c], __negTwos), __ones);
        __shapedPhasorOutput[c] = _mm_sub_ps(_mm_mul_ps(osc[c].getShapedPhasor(), __twos), __ones);
        enhancer[c].insertAuxSignals(osc[c].getPhasor(), osc[c].getStepSize(), osc[c].getEOCPulse(), osc[c].getDirection());
        __phasorOutput[c] = _mm_mul_ps(__phasorOutput[c], __negFives);
        __preEnhanceOutput[c] = osc[c].getOutput();

        if (swapEnhancerAndLPG) {
            __lpgInput = _mm_add_ps(__preEnhanceOutput[c], _mm_mul_ps(__subOscOut, _mm_set1_ps(params[SUB_OSC_LEVEL_PARAM].getValue())));
            __mainOutput[c] = lpg[c].process(__lpgInput, _mm_clamp_ps(_mm_add_ps(__trigger1, __trigger2), __zeros, __ones));
            __preEnhanceOutput[c] = _mm_mul_ps(__preEnhanceOutput[c], __fives);
            __mainOutput[c] = enhancer[c].process(__mainOutput[c], __enhance);
        }
        else {
            __mainOutput[c] = enhancer[c].process(__preEnhanceOutput[c], __enhance);
            __preEnhanceOutput[c] = _mm_mul_ps(__preEnhanceOutput[c], __fives);
            __lpgInput = _mm_add_ps(__mainOutput[c], _mm_mul_ps(__subOscOut, _mm_set1_ps(params[SUB_OSC_LEVEL_PARAM].getValue())));
            __mainOutput[c] = lpg[c].process(__lpgInput, _mm_clamp_ps(_mm_add_ps(__trigger1, __trigger2), __zeros, __ones));
        }

        __mainOutput[c] = _mm_mul_ps(__mainOutput[c], __fives);

        _mm_store_ps(outputs[PHASOR_OUTPUT].getVoltages(g), __phasorOutput[c]);
        _mm_store_ps(outputs[END_OF_CYCLE_OUTPUT].getVoltages(g), _mm_mul_ps(osc[c].getEOCPulse(), __fives));
        _mm_store_ps(outputs[SHAPED_PHASOR_OUTPUT].getVoltages(g), _mm_mul_ps(__shapedPhasorOutput[c], __fives));
        _mm_store_ps(outputs[RAW_OUTPUT].getVoltages(g), rawOutDCBlock[c].process(__preEnhanceOutput[c]));
        _mm_store_ps(outputs[ENHANCER_OUTPUT].getVoltages(g), enhancerOutDCBlock[c].process(_mm_mul_ps(enhancer[c].output, __fives)));
        _mm_store_ps(outputs[SUB_OSC_OUTPUT].getVoltages(g), _mm_mul_ps(__subOscOut, __fives));
        _mm_store_ps(outputs[MAIN_OUTPUT].getVoltages(g), mainOutDCBlock[c].process(__mainOutput[c]));
        _mm_store_ps(outputs[ENVELOPE_OUTPUT].getVoltages(g), _mm_mul_ps(lpg[c].__env, __tens));
    }

    outputs[PHASOR_OUTPUT].setChannels(numActiveChannels);
    outputs[END_OF_CYCLE_OUTPUT].setChannels(numActiveChannels);
    outputs[SHAPED_PHASOR_OUTPUT].setChannels(numActiveChannels);
    outputs[RAW_OUTPUT].setChannels(numActiveChannels);
    outputs[ENHANCER_OUTPUT].setChannels(numActiveChannels);
    outputs[SUB_OSC_OUTPUT].setChannels(numActiveChannels);
    outputs[MAIN_OUTPUT].setChannels(numActiveChannels);
    outputs[ENVELOPE_OUTPUT].setChannels(numActiveChannels);
}

void Terrorform::onSampleRateChange() {
    for(auto i = 0; i < kMaxNumGroups; ++i) {
        osc[i].setSampleRate(APP->engine->getSampleRate());
        enhancer[i].setSampleRate(APP->engine->getSampleRate());
        lpg[i].setSampleRate(APP->engine->getSampleRate());
        mainOutDCBlock[i].setSampleRate(APP->engine->getSampleRate());
        rawOutDCBlock[i].setSampleRate(APP->engine->getSampleRate());
        enhancerOutDCBlock[i].setSampleRate(APP->engine->getSampleRate());
    }
}

json_t* Terrorform::dataToJson()  {
    json_t *rootJ = json_object();
    json_object_set_new(rootJ, "panelStyle", json_integer(panelStyle));
    json_object_set_new(rootJ, "displayStyle", json_integer(displayStyle));
    json_object_set_new(rootJ, "lpgMode", json_integer(lpgMode));
    json_object_set_new(rootJ, "syncChoice", json_integer(syncChoice));

    char str[25];
    json_t* userWavesJ = json_array();
    for (auto bank = 0; bank < TFORM_MAX_BANKS; ++bank) {
        json_t* userWaveJ = json_object();
        json_object_set_new(userWaveJ, "bank", json_integer(bank));
        if(userWaveTableFilled[bank] == false) {
            json_object_set_new(userWaveJ, "numWaves", json_integer(0));
            continue;
        }

        json_object_set_new(userWaveJ, "name", json_string(userWaveTableNames[bank].c_str()));
        json_t* tableJ = json_array();
        for (auto wave = 0; wave < userWaveTableSizes[bank]; ++wave) {
            json_t* waveJ = json_array();
            for (auto i = 0; i < TFORM_MAX_WAVELENGTH; ++i) {
                sprintf(str, "%e", userWaveTableData[bank][wave][i]);
                json_t* valueJ = json_string(str);
                json_array_append_new(waveJ, valueJ);
            }
            json_array_append_new(tableJ, waveJ);
        }
        json_object_set_new(userWaveJ, "waveTableData", tableJ);
        json_array_append_new(userWavesJ, userWaveJ);
    }
    json_object_set_new(rootJ, "userWaves", userWavesJ);
    return rootJ;
}

void Terrorform::dataFromJson(json_t *rootJ) {
    json_t *panelStyleJ = json_object_get(rootJ, "panelStyle");
    json_t *displayStyleJ = json_object_get(rootJ, "displayStyle");
    json_t *lpgModeJ = json_object_get(rootJ, "lpgMode");
    json_t *syncChoiceJ = json_object_get(rootJ, "syncChoice");

    panelStyle = json_integer_value(panelStyleJ);
    displayStyle = json_integer_value(displayStyleJ);
    lpgMode = json_integer_value(lpgModeJ);
    syncChoice = json_integer_value(syncChoiceJ);

    panelStyle = panelStyle > 1 ? 1 : panelStyle;
    displayStyle = displayStyle > 4 ? 4 : displayStyle;
    lpgMode = lpgMode > 3 ? 3 : lpgMode;
    syncChoice = syncChoice > QuadOsc::SyncModes::NUM_SYNC_MODES - 1 ? QuadOsc::SyncModes::NUM_SYNC_MODES - 1 : syncChoice;

    int destBank;
    int numWaves;
    clearUserWaveTables();

    json_t *userWavesJ = json_object_get(rootJ, "userWaves");
    numUserWaveTables = (int) json_array_size(userWavesJ);
    if (numUserWaveTables > 64) {
        numUserWaveTables = 64;
    }

    for (auto i = 0; i < numUserWaveTables; ++i) {
        json_t* userWaveJ = json_array_get(userWavesJ, i);
        json_t* destBankJ = json_object_get(userWaveJ, "bank");
        json_t* nameJ = json_object_get(userWaveJ, "name");
        json_t* tableJ = json_object_get(userWaveJ, "waveTableData");

        destBank = json_integer_value(destBankJ);
        numWaves = (int) json_array_size(tableJ);
        if (numWaves > 64) {
            numWaves = 64;
        }
        if (numWaves < 0) {
            numWaves = 0;
        }

        userWaveTableNames[destBank] = std::string(json_string_value(nameJ));
        if (numWaves) {
            userWaveTableSizes[destBank] = numWaves;
            userWaveTableFilled[destBank] = true;
        }
        else {
            userWaveTableSizes[destBank] = 1;
        }

        for (auto wave = 0; wave < numWaves; ++wave) {
            json_t *waveJ = json_array_get(tableJ, wave);
            for(auto i = 0; i < TFORM_MAX_WAVELENGTH; ++i) {
                json_t *valueJ = json_array_get(waveJ, i);
                userWaveTableData[destBank][wave][i] = atof(json_string_value(valueJ));
            }
        }
    }
}

void Terrorform::clearBank(int bankNum) {
    for (int wave = 0; wave < TFORM_MAX_NUM_WAVES; ++wave) {
        for (int i = 0; i < TFORM_MAX_WAVELENGTH; ++i) {
            userWaveTableData[bankNum][wave][i] = 0.0;
        }
    }
    userWaveTableFilled[bankNum] = false;
    userWaveTableSizes[bankNum] = 1;
    userWaveTableNames[bankNum] = "EMPTY_" + std::to_string(bankNum + 1);
}

void Terrorform::clearUserWaveTables() {
    for (int i = 0; i < TFORM_MAX_BANKS; ++i) {
        clearBank(i);
    }
}

void Terrorform::cloneBank(int sourceBank, int destBank, int startWave, int endWave) {
    int k = startWave;
    float a = 0.f;
    for (int i = 0; i < TFORM_MAX_NUM_WAVES; ++i) {
        for (int j = 0; j < TFORM_MAX_WAVELENGTH; ++j) {
            a = k <= endWave ? userWaveTableData[sourceBank][k][j] : 0.f;
            userWaveTableData[destBank][i][j] = a;
        }
        ++k;
    }
    userWaveTableFilled[destBank] = userWaveTableFilled[sourceBank];
    userWaveTableSizes[destBank] =  (endWave - startWave) + 1;
    userWaveTableNames[destBank] = userWaveTableNames[sourceBank];
}

void Terrorform::moveBank(int sourceBank, int destBank) {
    for (int i = 0; i < TFORM_MAX_NUM_WAVES; ++i) {
        for (int j = 0; j < TFORM_MAX_WAVELENGTH; ++j) {
            userWaveTableData[destBank][i][j] = userWaveTableData[sourceBank][i][j];
            userWaveTableData[sourceBank][i][j] = 0.f;
        }
    }
    userWaveTableSizes[destBank] = userWaveTableSizes[sourceBank];
    userWaveTableFilled[destBank] = userWaveTableFilled[sourceBank];
    userWaveTableNames[destBank] = userWaveTableNames[sourceBank];
    clearBank(sourceBank);
}

void Terrorform::defragmentBanks() {
    for (int i = 0; i < TFORM_MAX_BANKS; ++i) {
        if (!userWaveTableFilled[i]) {
            for(int j = i; j < TFORM_MAX_BANKS; ++j) {
                if(userWaveTableFilled[j]) {
                    moveBank(j, i);
                    break;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void TerrorformPanelStyleItem::onAction(const event::Action &e) {
    module->panelStyle = panelStyle;
}

void TerrorformPanelStyleItem::step() {
    rightText = (module->panelStyle == panelStyle) ? "✔" : "";
    MenuItem::step();
}

void TerrorformDisplayStyleItem::onAction(const event::Action &e) {
    module->displayStyle = displayStyle;
}

void TerrorformDisplayStyleItem::step() {
    rightText = (module->displayStyle == displayStyle) ? "✔" : "";
    MenuItem::step();
}

void TerrorformManagerItem::onAction(const event::Action &e) {
    openMenu();
}

void TerrorformDisplayCVItem::onAction(const event::Action &e) {
    module->displayCV ^= true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

TerrorformWidget::TerrorformWidget(Terrorform* module) {

    // Welcome to Janksville, the jankiest place on earth
    const std::string panelFilenames[NUM_TRRFORM_PANELS] = {"res/TerrorformDark.svg",
                                                            "res/TerrorformLight.svg",
                                                            "res/TerrorformDarkManager.svg",
                                                            "res/TerrorformLightManager.svg"};

    setModule(module);
    setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, panelFilenames[TRRFORM_DARK_PANEL_NORMAL])));
    for(auto i = 1; i < NUM_TRRFORM_PANELS; ++i) {
        SvgPanel* newPanel = new SvgPanel;
        newPanel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, panelFilenames[i])));
        newPanel->visible = false;
        panels[i] = newPanel;
        addChild(panels[i]);
    }
    panels[0] = panel;

    addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
    addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
    addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    // Make jacks
    addInput(createInputCentered<PJ301MDarkSmall>(vOct1InputPos, module, Terrorform::VOCT_1_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(vOct2InputPos, module, Terrorform::VOCT_2_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(bankInput1Pos, module, Terrorform::BANK_INPUT_1));
    addInput(createInputCentered<PJ301MDarkSmall>(bankInput2Pos, module, Terrorform::BANK_INPUT_2));
    addInput(createInputCentered<PJ301MDarkSmall>(waveInput1Pos, module, Terrorform::WAVE_INPUT_1));
    addInput(createInputCentered<PJ301MDarkSmall>(waveInput2Pos, module, Terrorform::WAVE_INPUT_2));
    addInput(createInputCentered<PJ301MDarkSmall>(shapeTypeInput1Pos, module, Terrorform::SHAPE_TYPE_INPUT_1));
    addInput(createInputCentered<PJ301MDarkSmall>(shapeTypeInput2Pos, module, Terrorform::SHAPE_TYPE_INPUT_2));
    addInput(createInputCentered<PJ301MDarkSmall>(shapeDepthInput1Pos, module, Terrorform::SHAPE_DEPTH_INPUT_1));
    addInput(createInputCentered<PJ301MDarkSmall>(shapeDepthInput2Pos, module, Terrorform::SHAPE_DEPTH_INPUT_2));
    addInput(createInputCentered<PJ301MDarkSmall>(enhanceTypeInput1Pos, module, Terrorform::ENHANCE_TYPE_INPUT_1));
    addInput(createInputCentered<PJ301MDarkSmall>(enhanceTypeInput2Pos, module, Terrorform::ENHANCE_TYPE_INPUT_2));
    addInput(createInputCentered<PJ301MDarkSmall>(enhanceDepthInput1Pos, module, Terrorform::ENHANCE_DEPTH_INPUT_1));
    addInput(createInputCentered<PJ301MDarkSmall>(enhanceDepthInput2Pos, module, Terrorform::ENHANCE_DEPTH_INPUT_2));
    addInput(createInputCentered<PJ301MDarkSmall>(vcaAInputPos, module, Terrorform::FM_A_VCA_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(fmA1InputPos, module, Terrorform::FM_A1_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(fmA2InputPos, module, Terrorform::FM_A2_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(vcaBInputPos, module, Terrorform::FM_B_VCA_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(fmB1InputPos, module, Terrorform::FM_B1_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(fmB2InputPos, module, Terrorform::FM_B2_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(syncInput1Pos, module, Terrorform::SYNC_1_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(syncInput2Pos, module, Terrorform::SYNC_2_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(attackInput1Pos, module, Terrorform::ATTACK_1_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(attackInput2Pos, module, Terrorform::ATTACK_2_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(decayInput1Pos, module, Terrorform::DECAY_1_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(decayInput2Pos, module, Terrorform::DECAY_2_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(triggerInput1Pos, module, Terrorform::TRIGGER_1_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(triggerInput2Pos, module, Terrorform::TRIGGER_2_INPUT));
    addInput(createInputCentered<PJ301MDarkSmall>(skewInputPos, module, Terrorform::SKEW_INPUT));

    addOutput(createOutputCentered<PJ301MDarkSmallOut>(phasorOutPos, module, Terrorform::PHASOR_OUTPUT));
    addOutput(createOutputCentered<PJ301MDarkSmallOut>(eocOutPos, module, Terrorform::END_OF_CYCLE_OUTPUT));
    addOutput(createOutputCentered<PJ301MDarkSmallOut>(shapedOutPos, module, Terrorform::SHAPED_PHASOR_OUTPUT));
    addOutput(createOutputCentered<PJ301MDarkSmallOut>(rawOutPos, module, Terrorform::RAW_OUTPUT));
    addOutput(createOutputCentered<PJ301MDarkSmallOut>(enhancerOutPos, module, Terrorform::ENHANCER_OUTPUT));
    addOutput(createOutputCentered<PJ301MDarkSmallOut>(subOutPos, module, Terrorform::SUB_OSC_OUTPUT));
    addOutput(createOutputCentered<PJ301MDarkSmallOut>(mainOutPos, module, Terrorform::MAIN_OUTPUT));
    addOutput(createOutputCentered<PJ301MDarkSmallOut>(envOutPos, module, Terrorform::ENVELOPE_OUTPUT));

    // Knobs
    octaveKnob = createParamCentered<RoganMedBlue>(octavePos, module, Terrorform::OCTAVE_PARAM);
    octaveKnob->smooth = false;
    octaveKnob->snap = true;
    addParam(octaveKnob);
    coarseKnob = createParamCentered<RoganMedBlue>(coarsePos, module, Terrorform::COARSE_PARAM);
    addParam(coarseKnob);
    fineKnob = createParamCentered<RoganMedBlue>(finePos, module, Terrorform::FINE_PARAM);
    addParam(fineKnob);

    bankKnob = createParamCentered<RoganMedPurpleWithModeText>(bankPos, module, Terrorform::BANK_PARAM);
    bankKnob->smooth = false;
    bankKnob->snap = true;
    addParam(bankKnob);
    waveKnob = createParamCentered<RoganMedPurple>(wavePos, module, Terrorform::WAVE_PARAM);
    addParam(waveKnob);

    shapeTypeKnob = createParamCentered<RoganMedRedWithModeText>(shapeTypePos, module, Terrorform::SHAPE_TYPE_PARAM);
    shapeTypeKnob->smooth = false;
    shapeTypeKnob->snap = true;
    addParam(shapeTypeKnob);
    shapeDepthKnob = createParamCentered<RoganMedRed>(shapeDepthPos, module, Terrorform::SHAPE_DEPTH_PARAM);
    addParam(shapeDepthKnob);

    enhanceTypeKnob = createParamCentered<RoganMedGreenWithModeText>(enhanceTypePos, module, Terrorform::ENHANCE_TYPE_PARAM);
    enhanceTypeKnob->smooth = false;
    enhanceTypeKnob->snap = true;
    addParam(enhanceTypeKnob);
    enhanceDepthKnob = createParamCentered<RoganMedGreen>(enhanceDepthPos, module, Terrorform::ENHANCE_DEPTH_PARAM);
    addParam(enhanceDepthKnob);

    attackKnob = createParamCentered<RoganMedMustard>(lpgAttackPos, module, Terrorform::LPG_ATTACK_PARAM);
    addParam(attackKnob);
    decayKnob = createParamCentered<RoganMedMustard>(lpgDecayPos, module, Terrorform::LPG_DECAY_PARAM);
    addParam(decayKnob);

    addParam(createParamCentered<RoganSmallWhite>(skewPos, module, Terrorform::SKEW_PARAM));
    addParam(createParamCentered<RoganSmallWhite>(subOscLevelPos, module, Terrorform::SUB_OSC_LEVEL_PARAM));
    addParam(createParamCentered<RoganSmallWhite>(subOscWavePos, module, Terrorform::SUB_OSC_WAVE_PARAM));

    vOct1CV = createParamCentered<RoganSmallBlue>(vOct1CVPos, module, Terrorform::VOCT_1_CV_PARAM);
    vOct2CV = createParamCentered<RoganSmallBlue>(vOct2CVPos, module, Terrorform::VOCT_2_CV_PARAM);
    addParam(vOct1CV);
    addParam(vOct2CV);
    bankCV1 = createParamCentered<RoganSmallPurple>(bankCV1Pos, module, Terrorform::BANK_CV_1_PARAM);
    bankCV2 = createParamCentered<RoganSmallPurple>(bankCV2Pos, module, Terrorform::BANK_CV_2_PARAM);
    waveCV1 = createParamCentered<RoganSmallPurple>(waveCV1Pos, module, Terrorform::WAVE_CV_1_PARAM);
    waveCV2 = createParamCentered<RoganSmallPurple>(waveCV2Pos, module, Terrorform::WAVE_CV_2_PARAM);
    addParam(bankCV1);
    addParam(bankCV2);
    addParam(waveCV1);
    addParam(waveCV2);

    shapeTypeCV1 = createParamCentered<RoganSmallRed>(shapeTypeCV1Pos, module, Terrorform::SHAPE_TYPE_CV_1_PARAM);
    shapeTypeCV2 = createParamCentered<RoganSmallRed>(shapeTypeCV2Pos, module, Terrorform::SHAPE_TYPE_CV_2_PARAM);
    shapeDepthCV1 = createParamCentered<RoganSmallRed>(shapeDepthCV1Pos, module, Terrorform::SHAPE_DEPTH_CV_1_PARAM);
    shapeDepthCV2 = createParamCentered<RoganSmallRed>(shapeDepthCV2Pos, module, Terrorform::SHAPE_DEPTH_CV_2_PARAM);
    addParam(shapeTypeCV1);
    addParam(shapeTypeCV2);
    addParam(shapeDepthCV1);
    addParam(shapeDepthCV2);

    enhanceTypeCV1 = createParamCentered<RoganSmallGreen>(enhanceTypeCV1Pos, module, Terrorform::ENHANCE_TYPE_CV_1_PARAM);
    enhanceTypeCV2 = createParamCentered<RoganSmallGreen>(enhanceTypeCV2Pos, module, Terrorform::ENHANCE_TYPE_CV_2_PARAM);
    enhanceDepthCV1 = createParamCentered<RoganSmallGreen>(enhanceDepthCV1Pos, module, Terrorform::ENHANCE_DEPTH_CV_1_PARAM);
    enhanceDepthCV2 = createParamCentered<RoganSmallGreen>(enhanceDepthCV2Pos, module, Terrorform::ENHANCE_DEPTH_CV_2_PARAM);
    addParam(enhanceTypeCV1);
    addParam(enhanceTypeCV2);
    addParam(enhanceDepthCV1);
    addParam(enhanceDepthCV2);

    lpgAttackCV1 = createParamCentered<RoganSmallMustard>(lpgAttackCV1Pos, module, Terrorform::LPG_ATTACK_CV_1_PARAM);
    lpgAttackCV2 = createParamCentered<RoganSmallMustard>(lpgAttackCV2Pos, module, Terrorform::LPG_ATTACK_CV_2_PARAM);
    lpgDecayCV1 = createParamCentered<RoganSmallMustard>(lpgDecayCV1Pos, module, Terrorform::LPG_DECAY_CV_1_PARAM);
    lpgDecayCV2 = createParamCentered<RoganSmallMustard>(lpgDecayCV2Pos, module, Terrorform::LPG_DECAY_CV_2_PARAM);
    addParam(lpgAttackCV1);
    addParam(lpgAttackCV2);
    addParam(lpgDecayCV1);
    addParam(lpgDecayCV2);

    addParam(createParamCentered<RoganSmallWhite>(vcaAPos, module, Terrorform::FM_A_VCA_ATTEN_PARAM));
    addParam(createParamCentered<RoganSmallWhite>(vcaBPos, module, Terrorform::FM_B_VCA_ATTEN_PARAM));
    addParam(createParamCentered<RoganSmallWhite>(fmA1Pos, module, Terrorform::FM_A1_ATTEN_PARAM));
    addParam(createParamCentered<RoganSmallWhite>(fmA2Pos, module, Terrorform::FM_A2_ATTEN_PARAM));
    addParam(createParamCentered<RoganSmallWhite>(fmB1Pos, module, Terrorform::FM_B1_ATTEN_PARAM));
    addParam(createParamCentered<RoganSmallWhite>(fmB2Pos, module, Terrorform::FM_B2_ATTEN_PARAM));

    // Back text
    auto makeBackText = [=](const Vec& pos, int length, const NVGalign& align) {
        DynamicText* t = new DynamicText;
        t->size = 10;
        t->box.pos = pos;
        t->box.size = Vec(82, 14);
        t->visibility = nullptr;
        t->viewMode = ACTIVE_LOW_VIEW;
        t->horzAlignment = align;
        t->setFont(DynamicText::FontMode::FONT_MODE_7SEG);
        t->text = make_shared<std::string>(length, '~');
        t->customColor = nvgRGB(cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BACK][0],
                                cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BACK][1],
                                cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BACK][2]);
        return t;
    };

    auto setupFrontText = [=](DynamicText* t, DynamicText* tBlur1, DynamicText* tBlur2,
                             std::shared_ptr<std::string> text, const Vec& pos,
                             const NVGalign& align) {
        tBlur1->size = 10;
        tBlur1->box.pos = pos;
        tBlur1->box.size = Vec(82, 14);
        tBlur1->visibility = nullptr;
        tBlur1->viewMode = ACTIVE_LOW_VIEW;
        tBlur1->horzAlignment = align;
        tBlur1->setFont(DynamicText::FontMode::FONT_MODE_7SEG);
        tBlur1->text = text;
        tBlur1->customColor = nvgRGBA(cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_1][0],
                                      cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_1][1],
                                      cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_1][2],
                                      cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_1][3]);
        tBlur1->blur = 10.f;

        tBlur2->size = 10;
        tBlur2->box.pos = pos;
        tBlur2->box.size = Vec(82, 14);
        tBlur2->visibility = nullptr;
        tBlur2->viewMode = ACTIVE_LOW_VIEW;
        tBlur2->horzAlignment = align;
        tBlur2->setFont(DynamicText::FontMode::FONT_MODE_7SEG);
        tBlur2->text = text;
        tBlur2->customColor = nvgRGBA(cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_2][0],
                                      cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_2][1],
                                      cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_2][2],
                                      cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_BLUR_2][3]);
        tBlur2->blur = 8.f;

        t->size = 10;
        t->box.pos = pos;
        t->box.size = Vec(82, 14);
        t->visibility = nullptr;
        t->viewMode = ACTIVE_LOW_VIEW;
        t->horzAlignment = align;
        t->setFont(DynamicText::FontMode::FONT_MODE_7SEG);
        t->text = text;
        t->customColor = nvgRGB(cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_FRONT][0],
                                cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_FRONT][1],
                                cellDisplayColours[CELL_RED_LED_COLOUR][CELL_DISPLAY_FRONT][2]);
    };


    bool inBrowser = module == nullptr ? true : false;

    // Back Text
    bankBackText = makeBackText(bankTextPos, 13, NVG_ALIGN_LEFT);
    addChild(bankBackText);
    shapeBackText = makeBackText(shapeTextPos, 13, NVG_ALIGN_LEFT);
    addChild(shapeBackText);
    enhanceBackText = makeBackText(enhanceTextPos, 13, NVG_ALIGN_LEFT);
    addChild(enhanceBackText);
    syncBackText = makeBackText(syncTextPos, 10, NVG_ALIGN_CENTER);
    addChild(syncBackText);

    // Wave Text
    bankStr = std::make_shared<std::string>(inBrowser ? "NEVER" : bankNames[0]);
    bankBlurText = new DynamicText;
    bankBlurText2 = new DynamicText;
    bankText = new DynamicText;
    setupFrontText(bankText, bankBlurText, bankBlurText2, bankStr, bankTextPos, NVG_ALIGN_LEFT);
    addChild(bankBlurText);
    addChild(bankBlurText2);
    addChild(bankText);

    waveStr = std::make_shared<std::string>("0");
    waveBlurText = new DynamicText;
    waveBlurText2 = new DynamicText;
    waveText = new DynamicText;
    setupFrontText(waveText, waveBlurText, waveBlurText2, waveStr, waveTextPos, NVG_ALIGN_RIGHT);
    addChild(waveBlurText);
    addChild(waveBlurText2);
    addChild(waveText);

    // Shape Text
    shapeTypeStr = make_shared<std::string>(inBrowser ? "GONNA" : shapeNames[0]);
    shapeBlurText = new DynamicText;
    shapeBlurText2 = new DynamicText;
    shapeText = new DynamicText;
    setupFrontText(shapeText, shapeBlurText, shapeBlurText2, shapeTypeStr, shapeTextPos, NVG_ALIGN_LEFT);
    addChild(shapeBlurText);
    addChild(shapeBlurText2);
    addChild(shapeText);

    shapeDepthStr = std::make_shared<std::string>("0");
    shapeDepthBlurText = new DynamicText;
    shapeDepthBlurText2 = new DynamicText;
    shapeDepthText = new DynamicText;
    setupFrontText(shapeDepthText, shapeDepthBlurText, shapeDepthBlurText2, shapeDepthStr, shapeDepthTextPos, NVG_ALIGN_RIGHT);
    addChild(shapeDepthBlurText);
    addChild(shapeDepthBlurText2);
    addChild(shapeDepthText);

    // Enhance Text
    enhanceTypeStr = make_shared<std::string>(inBrowser ? "LET_YOU" : enhanceNames[0]);
    enhanceBlurText = new DynamicText;
    enhanceBlurText2 = new DynamicText;
    enhanceText = new DynamicText;
    setupFrontText(enhanceText, enhanceBlurText, enhanceBlurText2, enhanceTypeStr, enhanceTextPos, NVG_ALIGN_LEFT);
    addChild(enhanceBlurText);
    addChild(enhanceBlurText2);
    addChild(enhanceText);

    enhanceDepthStr = std::make_shared<std::string>("0");
    enhanceDepthBlurText = new DynamicText;
    enhanceDepthBlurText2 = new DynamicText;
    enhanceDepthText = new DynamicText;
    setupFrontText(enhanceDepthText, enhanceDepthBlurText, enhanceDepthBlurText2, enhanceDepthStr, enhanceDepthTextPos, NVG_ALIGN_RIGHT);
    addChild(enhanceDepthBlurText);
    addChild(enhanceDepthBlurText2);
    addChild(enhanceDepthText);

    // Sync Text
    syncStr = make_shared<std::string>(inBrowser ? "DOWN" : syncNames[0]);
    syncBlurText = new DynamicText;
    syncBlurText2 = new DynamicText;
    syncText = new DynamicText;
    setupFrontText(syncText, syncBlurText, syncBlurText2, syncStr, syncTextPos, NVG_ALIGN_CENTER);
    addChild(syncBlurText);
    addChild(syncBlurText2);
    addChild(syncText);

    // Yeaaaahhhh I know all display stuff should be wrapped up in a class.
    // I'll tidy my room later mum!
    if (module) {
        auto setOnHoverColour = [=](DynamicText* backText, DynamicText* frontText,
                                    DynamicText* blurText1, DynamicText* blurText2) {
            backText->customColor = nvgRGB(cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BACK][0],
                                           cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BACK][1],
                                           cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BACK][2]);
            frontText->customColor = nvgRGB(cellDisplayColours[displayStyle + 1][CELL_DISPLAY_FRONT][0],
                                            cellDisplayColours[displayStyle + 1][CELL_DISPLAY_FRONT][1],
                                            cellDisplayColours[displayStyle + 1][CELL_DISPLAY_FRONT][2]);
            blurText1->customColor = nvgRGBA(cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_1][0],
                                             cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_1][1],
                                             cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_1][2],
                                             cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_1][3]);
            blurText2->customColor = nvgRGBA(cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_2][0],
                                             cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_2][1],
                                             cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_2][2],
                                             cellDisplayColours[displayStyle + 1][CELL_DISPLAY_BLUR_2][3]);
        };

        auto setOnLeaveColour = [=](DynamicText* backText, DynamicText* frontText,
                                    DynamicText* blurText1, DynamicText* blurText2) {
            backText->customColor = nvgRGB(cellDisplayColours[displayStyle][CELL_DISPLAY_BACK][0],
                                           cellDisplayColours[displayStyle][CELL_DISPLAY_BACK][1],
                                           cellDisplayColours[displayStyle][CELL_DISPLAY_BACK][2]);
            frontText->customColor = nvgRGB(cellDisplayColours[displayStyle][CELL_DISPLAY_FRONT][0],
                                            cellDisplayColours[displayStyle][CELL_DISPLAY_FRONT][1],
                                            cellDisplayColours[displayStyle][CELL_DISPLAY_FRONT][2]);
            blurText1->customColor = nvgRGBA(cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][0],
                                             cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][1],
                                             cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][2],
                                             cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][3]);
            blurText2->customColor = nvgRGBA(cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][0],
                                             cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][1],
                                             cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][2],
                                             cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][3]);
        };

        bankMenu = createDynamicMenu(bankTextPos, bankText->box.size,
                                     bankMenuItems, true, false, 16);
        bankMenu->onMouseEnter = [=]() {
            setOnHoverColour(bankBackText, bankText, bankBlurText, bankBlurText2);
        };

        bankMenu->onMouseLeave = [=]() {
            setOnLeaveColour(bankBackText, bankText, bankBlurText, bankBlurText2);
        };

        bankMenu->setChoice = [=](int i) {
            bankKnob->paramQuantity->setValue((float)i);
        };
        addChild(bankMenu);

        shapeMenu = createDynamicMenu(shapeTextPos, shapeText->box.size,
                                      shapeMenuItems, true, false, 0);
        shapeMenu->onMouseEnter = [=]() {
            setOnHoverColour(shapeBackText, shapeText, shapeBlurText, shapeBlurText2);
        };

        shapeMenu->onMouseLeave = [=]() {
            setOnLeaveColour(shapeBackText, shapeText, shapeBlurText, shapeBlurText2);
        };

        shapeMenu->setChoice = [=](int i) {
            shapeTypeKnob->paramQuantity->setValue((float)i);
        };
        addChild(shapeMenu);

        enhanceMenu = createDynamicMenu(enhanceTextPos, enhanceText->box.size,
                                        enhanceMenuItems, true, false, 0);
        enhanceMenu->onMouseEnter = [=]() {
            setOnHoverColour(enhanceBackText, enhanceText, enhanceBlurText, enhanceBlurText2);
        };

        enhanceMenu->onMouseLeave = [=]() {
            setOnLeaveColour(enhanceBackText, enhanceText, enhanceBlurText, enhanceBlurText2);
        };

        enhanceMenu->setChoice = [=](int i) {
            enhanceTypeKnob->paramQuantity->setValue((float)i);
        };
        addChild(enhanceMenu);

        syncMenu = createDynamicMenu(syncTextPos.minus(Vec(syncText->box.size.x / 2.f, 0.f)), syncText->box.size,
                                     syncMenuItems, true, true, 0);
        syncMenu->onMouseEnter = [=]() {
            setOnHoverColour(syncBackText, syncText, syncBlurText, syncBlurText2);
        };

        syncMenu->onMouseLeave = [=]() {
            setOnLeaveColour(syncBackText, syncText, syncBlurText, syncBlurText2);
        };

        syncMenu->setChoice = [=](int i) {
            module->syncChoice = i;
        };

        addChild(syncMenu);
    }

    // LPG Buttons
    lpgButton = createParamCentered<LightLEDButtonWithModeText>(lpgModeSwitchPos, module, Terrorform::LPG_MODE_SWITCH_PARAM);
    addParam(lpgButton);

    lpgLongTimeButton = createParamCentered<LightLEDButtonWithModeText>(lpgLongTimeSwitchPos, module, Terrorform::LPG_LONG_TIME_SWITCH_PARAM);
    lpgLongTimeButton->momentary = false;
    addParam(lpgLongTimeButton);

    lpgVelocityButton = createParamCentered<LightLEDButtonWithModeText>(lpgVelocitySwitchPos, module, Terrorform::LPG_VELOCITY_SWITCH_PARAM);
    lpgVelocityButton->momentary = false;
    addParam(lpgVelocityButton);

    lpgTrigButton = createParamCentered<LightLEDButtonWithModeText>(lpgTrigSwitchPos, module, Terrorform::LPG_TRIGGER_SWITCH_PARAM);
    lpgTrigButton->momentary = false;
    addParam(lpgTrigButton);

    lpgButtonLight = createLightCentered<MediumLight<RedGreenBlueLight>>(lpgModeSwitchPos, module, Terrorform::LPG_RED_LIGHT);
    addChild(lpgButtonLight);

    lpgLongTimeButtonLight = createLightCentered<MediumLight<RedLight>>(lpgLongTimeSwitchPos, module, Terrorform::LPG_LONG_TIME_LIGHT);
    addChild(lpgLongTimeButtonLight);

    lpgVelocityButtonLight = createLightCentered<MediumLight<RedLight>>(lpgVelocitySwitchPos, module, Terrorform::LPG_VELOCITY_LIGHT);
    addChild(lpgVelocityButtonLight);

    lpgTrigButtonLight = createLightCentered<MediumLight<RedLight>>(lpgTrigSwitchPos, module, Terrorform::LPG_TRIGGER_LIGHT);
    addChild(lpgTrigButtonLight);

    // Sync, FM, and Enhancer Buttons
    weakSync1Button = createParamCentered<LightLEDButtonWithModeText>(weakSyncSwitch1Pos, module, Terrorform::WEAK_SYNC_1_SWITCH_PARAM);
    weakSync1Button->momentary = false;
    addChild(weakSync1Button);

    weakSync2Button = createParamCentered<LightLEDButtonWithModeText>(weakSyncSwitch2Pos, module, Terrorform::WEAK_SYNC_2_SWITCH_PARAM);
    weakSync2Button->momentary = false;
    addChild(weakSync2Button);

    phasorShapingOrderButton = createParamCentered<LightLEDButtonWithModeText>(postPMShapeButtonPos, module, Terrorform::POST_PM_SHAPE_PARAM);
    phasorShapingOrderButton->momentary = false;
    addChild(phasorShapingOrderButton);

    trueFMButton = createParamCentered<LightLEDButtonWithModeText>(trueFMButtonPos, module, Terrorform::TRUE_FM_SWITCH_PARAM);
    trueFMButton->momentary = false;
    addChild(trueFMButton);

    swapButton = createParamCentered<LightLEDButtonWithModeText>(swapButtonPos, module, Terrorform::SWAP_SWITCH_PARAM);
    swapButton->momentary = false;
    addChild(swapButton);

    lfoButton = createParamCentered<LightLEDButtonWithModeText>(lfoButtonPos, module, Terrorform::LFO_SWITCH_PARAM);
    lfoButton->momentary = false;
    addParam(lfoButton);

    zeroFreqButton = createParamCentered<LightLEDButtonWithModeText>(zeroFreqButtonPos, module, Terrorform::ZERO_SWITCH_PARAM);
    zeroFreqButton->momentary = false;
    addChild(zeroFreqButton);

    lfoButtonLight = createLightCentered<MediumLight<RedLight>>(lfoButtonPos, module, Terrorform::LFO_LIGHT);
    addChild(lfoButtonLight);

    zeroFreqLight = createLightCentered<MediumLight<RedLight>>(zeroFreqButtonPos, module, Terrorform::ZERO_LIGHT);
    addChild(zeroFreqLight);

    userBankButton = createParamCentered<LightLEDButtonWithModeText>(userBankSwitchPos, module, Terrorform::USER_BANK_SWITCH_PARAM);
    userBankButton->momentary = false;
    addParam(userBankButton);

    userBankLight = createLightCentered<MediumLight<RedLight>>(userBankSwitchPos, module, Terrorform::USER_BANK_LIGHT);
    addChild(userBankLight);

    displayCVButton = createParamCentered<LightLEDButtonWithModeText>(displayCVSwitchPos, module, Terrorform::DISPLAY_CV_SWITCH_PARAM);
    displayCVButton->momentary = false;
    addParam(displayCVButton);

    displayCVLight = createLightCentered<MediumLight<RedLight>>(displayCVSwitchPos, module, Terrorform::DISPLAY_CV_LIGHT);
    addChild(displayCVLight);

    addChild(createLightCentered<MediumLight<RedLight>>(weakSyncSwitch1Pos, module, Terrorform::WEAK_SYNC_1_LIGHT));
    addChild(createLightCentered<MediumLight<RedLight>>(weakSyncSwitch2Pos, module, Terrorform::WEAK_SYNC_2_LIGHT));
    addChild(createLightCentered<MediumLight<RedLight>>(trueFMButtonPos, module, Terrorform::TRUE_FM_LIGHT));
    addChild(createLightCentered<MediumLight<RedLight>>(postPMShapeButtonPos, module, Terrorform::POST_PM_SHAPE_LIGHT));
    addChild(createLightCentered<MediumLight<RedLight>>(swapButtonPos, module, Terrorform::SWAP_LIGHT));

    auto onExitEditor = [=]() {
        octaveKnob->visible = true;
        coarseKnob->visible = true;
        fineKnob->visible = true;
        bankKnob->visible = true;
        waveKnob->visible = true;
        shapeTypeKnob->visible = true;
        shapeDepthKnob->visible = true;
        enhanceTypeKnob->visible = true;
        enhanceDepthKnob->visible = true;
        attackKnob->visible = true;
        decayKnob->visible = true;

        bankBackText->visible = true;
        shapeBackText->visible = true;
        enhanceBackText->visible = true;

        bankText->visible = true;
        shapeText->visible = true;
        enhanceText->visible = true;
        waveText->visible = true;
        shapeDepthText->visible = true;
        enhanceDepthText->visible = true;

        bankBlurText->visible = true;
        bankBlurText2->visible = true;
        waveBlurText->visible = true;
        waveBlurText2->visible = true;
        shapeBlurText->visible = true;
        shapeBlurText2->visible = true;
        shapeDepthBlurText->visible = true;
        shapeDepthBlurText2->visible = true;
        enhanceBlurText->visible = true;
        enhanceBlurText2->visible = true;
        enhanceDepthBlurText->visible = true;
        enhanceDepthBlurText2->visible = true;

        vOct1CV->visible = true;
        vOct2CV->visible = true;
        bankCV1->visible = true;
        bankCV2->visible = true;
        waveCV1->visible = true;
        waveCV2->visible = true;
        shapeTypeCV1->visible = true;
        shapeTypeCV2->visible = true;
        shapeDepthCV1->visible = true;
        shapeDepthCV2->visible = true;
        enhanceTypeCV1->visible = true;
        enhanceTypeCV2->visible = true;
        enhanceDepthCV1->visible = true;
        enhanceDepthCV2->visible = true;
        lpgAttackCV1->visible = true;
        lpgAttackCV2->visible = true;
        lpgDecayCV1->visible = true;
        lpgDecayCV2->visible = true;

        lfoButton->visible = true;
        zeroFreqButton->visible = true;
        userBankButton->visible = true;
        displayCVButton->visible = true;
        lpgButton->visible = true;
        lpgLongTimeButton->visible = true;

        lfoButtonLight->visible = true;
        zeroFreqLight->visible = true;
        userBankLight->visible = true;
        displayCVLight->visible = true;
        lpgButtonLight->visible = true;
        lpgLongTimeButtonLight->visible = true;
        lpgVelocityButton->visible = true;
        lpgTrigButton->visible = true;
        lpgVelocityButtonLight->visible = true;
        lpgTrigButtonLight->visible = true;

        editor->visible = false;
        inEditorMode = false;
    };

    auto loadWAVFile = [=]() -> std::shared_ptr<std::vector<std::vector<float>>> {
        const char FILE_FILTERS[] = "WAV File (.wav):wav";
        std::string filename;

        osdialog_filters* filters = osdialog_filters_parse(FILE_FILTERS);
        DEFER({
            osdialog_filters_free(filters);
        });

        numChannels = 1;
        drwav_uint64 numSamples = 0;
        unsigned int sampleRate = 44100;

        if(newTable == NULL) {
            drwav_free(newTable);
        }
        newTable = NULL;

        // Open file
        if (dir.empty()) {
            dir = asset::user("");
        }
        char* path = osdialog_file(OSDIALOG_OPEN, dir.c_str(), filename.c_str(), filters);
        if (path) {
            newTable = drwav_open_file_and_read_f32(path, &numChannels, &sampleRate, &numSamples);
            std::string filepath(path);
            dir = extractDirectoryFromFilePath(filepath);
            std::cout << dir << std::endl;
            DEFER({
                std::free(path);
            });
        }

        // Prepare wave memory
        std::shared_ptr<std::vector<std::vector<float>>> waves = std::make_shared<std::vector<std::vector<float>>>();
        if (newTable == NULL) {
            return waves;
        }
        if (numChannels < 1) {
            drwav_free(newTable);
            return waves;
        }

        // Calculate required number of blocks, and zero pad when too short
        auto numBlocks = 0;
        auto numFrames = numSamples / numChannels;
        bool needsZeroPadding = numFrames < 256;

        if (!needsZeroPadding) {
            numFrames -= numFrames % TFORM_MAX_WAVELENGTH;
            numBlocks = numFrames / TFORM_MAX_WAVELENGTH;
            numBlocks = numBlocks > TFORM_MAX_NUM_WAVES ? TFORM_MAX_NUM_WAVES : numBlocks;
        }
        else {
            float *newTableTemp = new float[numSamples];
            int newNumSamples = TFORM_MAX_WAVELENGTH * numChannels;

            memcpy(newTableTemp, newTable, sizeof(float) * numSamples);
            drwav_free(newTable);
            newTable = new float[newNumSamples];
            memcpy(newTable, newTableTemp, sizeof(float) * numSamples);
            delete[] newTableTemp;

            for (int i = numSamples; i < newNumSamples; ++i) {
                newTable[i] = 0.f;
            }
            numBlocks = 1;
        }

        // Copy .wav data into table
        int readPos = 0;
        waves->resize(numBlocks);
        for (int i = 0; i < numBlocks; ++i) {
            (*waves)[i].assign(256, 0.f);
            for (int j = 0; j < TFORM_MAX_WAVELENGTH; ++j) {
                (*waves)[i][j] = newTable[readPos];
                readPos += numChannels;
            }
        }
        return waves;
    };

    auto ingestNewTable = [=](int bank, int startWave, int endWave, const std::string name) {
        int numWaves = (endWave - startWave) + 1;
        int tableLength = numWaves * TFORM_MAX_WAVELENGTH;
        int readPos = 0;
        int startPos = startWave * TFORM_MAX_WAVELENGTH;
        int writePos = 0;
        int wave = 0;

        for (int i = 0; i < tableLength; ++i) {
            readPos = (startPos + i) * numChannels;
            wave = i / TFORM_MAX_WAVELENGTH;
            writePos = i % TFORM_MAX_WAVELENGTH;
            module->userWaveTableData[bank][wave][writePos] = newTable[readPos];
        }
        module->userWaveTableSizes[bank] = numWaves;
        module->userWaveTableFilled[bank] = true;
        module->userWaveTableNames[bank] = name;
        module->numUserWaveTables++;
        updateBankNames = true;
        drwav_free(newTable);
    };

    editor = createWidget<TFormEditor>(Vec(31, 28));
    editor->box.size.x = 238;
    editor->box.size.y = 195;
    editor->visible = false;
    editor->addOnExitCallback(onExitEditor);
    editor->addLoadWAVCallback(loadWAVFile);
    editor->addIngestTableCallback(ingestNewTable);
    editor->addExportCallback(std::bind(&TerrorformWidget::exportWavetables, this));
    editor->addImportCallback(std::bind(&TerrorformWidget::importWavetables, this));

    editor->addClearBankCallback([=](int bankNum){
        module->clearBank(bankNum);
        updateBankNames = true;
    });

    editor->addGetBankCallback([=](int bank, TerrorformWaveBank& waveBank) {
        waveBank.data.resize(module->userWaveTableSizes[bank]);
        for (unsigned long i = 0; i < waveBank.data.size(); ++i) {
            waveBank.data[i].resize(TFORM_MAX_WAVELENGTH);
            memcpy(waveBank.data[i].data(), module->userWaveTableData[bank][i], sizeof(float) * TFORM_MAX_WAVELENGTH);
        }
        waveBank.name = module->userWaveTableNames[bank];
    });

    editor->addRenameBankCallback([=](int bank, const std::string& name) {
        module->userWaveTableNames[bank] = name;
        updateBankNames = true;
    });

    editor->addCloneBankCallback([=](int sourceBank, int destBank, int startWave, int endWave) {
        module->cloneBank(sourceBank, destBank, startWave, endWave);
        updateBankNames = true;
    });

    editor->addMoveBankCallback([=](int sourceBank, int destBank) {
        module->moveBank(sourceBank, destBank);
        updateBankNames = true;
    });

    editor->addDefragmentCallback([=]() {
        module->defragmentBanks();
        updateBankNames = true;
    });

    addChild(editor);
}

void TerrorformWidget::appendContextMenu(Menu *menu) {
    Terrorform *module = dynamic_cast<Terrorform*>(this->module);
    assert(module);

    // Manager item
    menu->addChild(construct<MenuLabel>());

    MenuLabel* managerLabel = new MenuLabel;
    managerLabel->text = "User Bank Manager";
    menu->addChild(managerLabel);

    // Yeah, don't ask :')
    TerrorformManagerItem* managerItem = new TerrorformManagerItem;
    managerItem->text = "Open";
    managerItem->openMenu = [=]() {
        octaveKnob->visible = false;
        coarseKnob->visible = false;
        fineKnob->visible = false;
        bankKnob->visible = false;
        waveKnob->visible = false;
        shapeTypeKnob->visible = false;
        shapeDepthKnob->visible = false;
        enhanceTypeKnob->visible = false;
        enhanceDepthKnob->visible = false;
        attackKnob->visible = false;
        decayKnob->visible = false;

        bankBackText->visible = false;
        shapeBackText->visible = false;
        enhanceBackText->visible = false;

        bankText->visible = false;
        shapeText->visible = false;
        enhanceText->visible = false;
        waveText->visible = false;
        shapeDepthText->visible = false;
        enhanceDepthText->visible = false;

        bankBlurText->visible = false;
        bankBlurText2->visible = false;
        waveBlurText->visible = false;
        waveBlurText2->visible = false;
        shapeBlurText->visible = false;
        shapeBlurText2->visible = false;
        shapeDepthBlurText->visible = false;
        shapeDepthBlurText2->visible = false;
        enhanceBlurText->visible = false;
        enhanceBlurText2->visible = false;
        enhanceDepthBlurText->visible = false;
        enhanceDepthBlurText2->visible = false;

        vOct1CV->visible = false;
        vOct2CV->visible = false;
        bankCV1->visible = false;
        bankCV2->visible = false;
        waveCV1->visible = false;
        waveCV2->visible = false;
        shapeTypeCV1->visible = false;
        shapeTypeCV2->visible = false;
        shapeDepthCV1->visible = false;
        shapeDepthCV2->visible = false;
        enhanceTypeCV1->visible = false;
        enhanceTypeCV2->visible = false;
        enhanceDepthCV1->visible = false;
        enhanceDepthCV2->visible = false;
        lpgAttackCV1->visible = false;
        lpgAttackCV2->visible = false;
        lpgDecayCV1->visible = false;
        lpgDecayCV2->visible = false;

        lfoButton->visible = false;
        zeroFreqButton->visible = false;
        userBankButton->visible = false;
        displayCVButton->visible = false;
        lpgButton->visible = false;
        lpgLongTimeButton->visible = false;

        lfoButtonLight->visible = false;
        zeroFreqLight->visible = false;
        userBankLight->visible = false;
        displayCVLight->visible = false;
        lpgButtonLight->visible = false;
        lpgLongTimeButtonLight->visible = false;
        lpgVelocityButton->visible = false;
        lpgTrigButton->visible = false;
        lpgVelocityButtonLight->visible = false;
        lpgTrigButtonLight->visible = false;

        editor->visible = true;
        inEditorMode = true;
    };
    menu->addChild(managerItem);

    // Display style items
    menu->addChild(construct<MenuLabel>());

    MenuLabel* displayStyleLabel = new MenuLabel;
    displayStyleLabel->text = "Display style";
    menu->addChild(displayStyleLabel);

    TerrorformDisplayStyleItem* redLEDDisplayStyleItem = new TerrorformDisplayStyleItem;
    redLEDDisplayStyleItem->text = "Red LED";
    redLEDDisplayStyleItem->module = module;
    redLEDDisplayStyleItem->displayStyle = 0;
    menu->addChild(redLEDDisplayStyleItem);

    TerrorformDisplayStyleItem* yellowLEDDisplayStyleItem = new TerrorformDisplayStyleItem;
    yellowLEDDisplayStyleItem->text = "Yellow LED";
    yellowLEDDisplayStyleItem->module = module;
    yellowLEDDisplayStyleItem->displayStyle = 1;
    menu->addChild(yellowLEDDisplayStyleItem);

    TerrorformDisplayStyleItem* greenLEDDisplayStyleItem = new TerrorformDisplayStyleItem;
    greenLEDDisplayStyleItem->text = "Green LED";
    greenLEDDisplayStyleItem->module = module;
    greenLEDDisplayStyleItem->displayStyle = 2;
    menu->addChild(greenLEDDisplayStyleItem);

    TerrorformDisplayStyleItem* blueLEDDisplayStyleItem = new TerrorformDisplayStyleItem;
    blueLEDDisplayStyleItem->text = "Blue LED";
    blueLEDDisplayStyleItem->module = module;
    blueLEDDisplayStyleItem->displayStyle = 3;
    menu->addChild(blueLEDDisplayStyleItem);

    TerrorformDisplayStyleItem* whiteLEDDisplayStyleItem = new TerrorformDisplayStyleItem;
    whiteLEDDisplayStyleItem->text = "White LED";
    whiteLEDDisplayStyleItem->module = module;
    whiteLEDDisplayStyleItem->displayStyle = 4;
    menu->addChild(whiteLEDDisplayStyleItem);

    // Panel style items
    menu->addChild(construct<MenuLabel>());

    MenuLabel* panelStyleLabel = new MenuLabel;
    panelStyleLabel->text = "Panel style";
    menu->addChild(panelStyleLabel);

    TerrorformPanelStyleItem* darkPanelStyleItem = new TerrorformPanelStyleItem;
    darkPanelStyleItem->text = "Dark";
    darkPanelStyleItem->module = module;
    darkPanelStyleItem->panelStyle = 0;
    menu->addChild(darkPanelStyleItem);

    TerrorformPanelStyleItem* lightPanelStyleItem = new TerrorformPanelStyleItem;
    lightPanelStyleItem->text = "Light";
    lightPanelStyleItem->module = module;
    lightPanelStyleItem->panelStyle = 1;
    menu->addChild(lightPanelStyleItem);
 }

void TerrorformWidget::step() {
    if (module == nullptr) {
        Widget::step();
        return;
    }

    Terrorform* tform = dynamic_cast<Terrorform*>(module);

    int panelStyleOffset = tform->panelStyle;
    for (auto i = 0; i < NUM_TRRFORM_PANELS; ++i) {
        panels[i]->visible = false;
    }
    if (inEditorMode) {
        panels[TRRFORM_DARK_PANEL_EDITOR + panelStyleOffset]->visible = true;
    }
    else {
        panels[TRRFORM_DARK_PANEL_NORMAL + panelStyleOffset]->visible = true;
    }

    displayStyle = (TerrorformDisplayColourModes)(tform->displayStyle * 2);
    if (displayStyle != prevDisplayStyle) {
        changeDisplayStyle();
    }
    prevDisplayStyle = displayStyle;

    //// Display params
    // Wavetable knobs and Display
    bankChoice = tform->bankDisplay;
    if (userBankButton->paramQuantity->getValue() > 0.5f) {
        *bankStr = tform->userWaveTableNames[bankChoice];
    }
    else {
        *bankStr = bankNames[bankChoice];
    }

    std::replace(bankStr->begin(), bankStr->end(), ' ', '!');

    if ((tform->readFromUserWaves != prevReadUserWavesState)
        && !updateBankNames) {
        updateBankNames = true;
    }
    prevReadUserWavesState = tform->readFromUserWaves;

    if (updateBankNames) {
        updateBankNames = false;
        if(tform->readFromUserWaves) {
            bankMenu->_items = tform->userWaveTableNames;
        }
        else if (!dynamic_cast<Terrorform*>(module)->readFromUserWaves) {
            bankMenu->_items = bankMenuItems;
        }
    }
    bankKnobStep = (int)bankKnob->paramQuantity->getValue();
    bankKnobTooltipText = std::to_string(bankKnobStep) + " " + bankMenu->_items[bankKnobStep];
    bankKnob->setModeText(bankKnobTooltipText);

    float waveValue = (float)(tform->waveAmountDisplay);
    wavePercent = (int)(waveValue * 100.f);
    wavePercent = clamp(wavePercent, 0, 100);
    *waveStr = std::to_string(wavePercent);

    // Shape Knob and Display
    shapeTypeKnobStep = (int)shapeTypeKnob->paramQuantity->getValue();
    shapeTypeKnobTooltipText = std::to_string(shapeTypeKnobStep) + " " +
                               shapeMenu->_items[shapeTypeKnobStep];
    shapeTypeKnob->setModeText(shapeTypeKnobTooltipText);

    *shapeTypeStr = shapeNames[(int)(tform->shapeDisplay)];
    float shapeValue = (float)(tform->shapeAmountDisplay);
    shapeDepthPercent = (int)(shapeValue * 100.f);
    shapeDepthPercent = clamp(shapeDepthPercent, 0, 100);
    *shapeDepthStr = std::to_string(shapeDepthPercent);

    // Enhance Knob and Display
    enhanceTypeKnobStep = (int)enhanceTypeKnob->paramQuantity->getValue();
    enhanceTypeKnobTooltipText = std::to_string(enhanceTypeKnobStep) + " " +
                                 enhanceMenu->_items[enhanceTypeKnobStep];
    enhanceTypeKnob->setModeText(enhanceTypeKnobTooltipText);

    *enhanceTypeStr = enhanceNames[(int)(tform->enhanceDisplay)];
    float enhanceValue = (float)(tform->enhanceAmountDisplay);
    enhanceDepthPercent = (int)(enhanceValue * 100.f);
    enhanceDepthPercent = clamp(enhanceDepthPercent, 0, 100);
    *enhanceDepthStr = std::to_string(enhanceDepthPercent);

    int syncChoice = (int)tform->syncChoice;
    *syncStr = syncNames[syncChoice];
    if (syncMenu->_choice != syncChoice) {
        syncMenu->_choice = syncChoice;
    }

    // Report slots filled to editor
    for (auto i = 0; i < TFORM_MAX_BANKS; ++i) {
        editor->setSlotFilledFlag(i, tform->userWaveTableFilled[i]);
    }

    // LFO button tooltip
    if (lfoButton->paramQuantity->getValue()) {
        lfoButton->setModeText("On");
    }
    else {
        lfoButton->setModeText("Off");
    }

    // Zero freq button tooltip
    if (zeroFreqButton->paramQuantity->getValue()) {
        zeroFreqButton->setModeText("On");
    }
    else {
        zeroFreqButton->setModeText("Off");
    }

    // User bank button tooltip
    if (userBankButton->paramQuantity->getValue()) {
        userBankButton->setModeText("Yes");
    }
    else {
        userBankButton->setModeText("No");
    }

    // Display CV button tooltip
    if (displayCVButton->paramQuantity->getValue()) {
        displayCVButton->setModeText("Yes");
    }
    else {
        displayCVButton->setModeText("No");
    }

    // LPG mode button tooltip
    switch (tform->lpgMode) {
        case 1: lpgButton->setModeText("\nVCA"); break;
        case 2: lpgButton->setModeText("\nVCF"); break;
        case 3: lpgButton->setModeText("\nVCA + VCF"); break;
        default: lpgButton->setModeText("\nBypassed"); break;
    }

    // LPG long time button tooltip
    if (lpgLongTimeButton->paramQuantity->getValue()) {
        lpgLongTimeButton->setModeText("Long");
    }
    else {
        lpgLongTimeButton->setModeText("Short");
    }

    // LPG velocity sense button tooltip
    if (lpgVelocityButton->paramQuantity->getValue()) {
        lpgVelocityButton->setModeText("On");
    }
    else {
        lpgVelocityButton->setModeText("Off (Full level)");
    }

    // LPG trigger button tooltip
    if (lpgTrigButton->paramQuantity->getValue()) {
        lpgTrigButton->setModeText("On (Triggered)");
    }
    else {
        lpgTrigButton->setModeText("Off (Gated)");
    }

    // Phasor shaping order button tooltip
    if (phasorShapingOrderButton->paramQuantity->getValue()) {
        phasorShapingOrderButton->setModeText("\nPost phase mod");
    }
    else {
        phasorShapingOrderButton->setModeText("\nPre phase mod");
    }

    // Weak sync button tooltips
    if (weakSync1Button->paramQuantity->getValue()) {
        weakSync1Button->setModeText("On");
    }
    else {
        weakSync1Button->setModeText("Off");
    }

    if (weakSync2Button->paramQuantity->getValue()) {
        weakSync2Button->setModeText("On");
    }
    else {
        weakSync2Button->setModeText("Off");
    }

    // FM mode button tooltip
    if (trueFMButton->paramQuantity->getValue()) {
        trueFMButton->setModeText("True FM");
    }
    else {
        trueFMButton->setModeText("Phase Mod");
    }

    // Enhancer-LPG swap button tooltip
    if (swapButton->paramQuantity->getValue()) {
        swapButton->setModeText("\nLPG -> Enhancer");
    }
    else {
        swapButton->setModeText("\nEnhancer -> LPG");
    }

    Widget::step();
}

void TerrorformWidget::changeDisplayStyle() {
    auto setNewColour = [=](DynamicText* backText, DynamicText* frontText,
                            DynamicText* blurText1, DynamicText* blurText2) {
        if (backText) {
            backText->customColor = nvgRGB(cellDisplayColours[displayStyle][CELL_DISPLAY_BACK][0],
                                           cellDisplayColours[displayStyle][CELL_DISPLAY_BACK][1],
                                           cellDisplayColours[displayStyle][CELL_DISPLAY_BACK][2]);
        }

        frontText->customColor = nvgRGB(cellDisplayColours[displayStyle][CELL_DISPLAY_FRONT][0],
                                        cellDisplayColours[displayStyle][CELL_DISPLAY_FRONT][1],
                                        cellDisplayColours[displayStyle][CELL_DISPLAY_FRONT][2]);

        blurText1->customColor = nvgRGBA(cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][0],
                                         cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][1],
                                         cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][2],
                                         cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_1][3]);

        blurText2->customColor = nvgRGBA(cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][0],
                                         cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][1],
                                         cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][2],
                                         cellDisplayColours[displayStyle][CELL_DISPLAY_BLUR_2][3]);
    };
    setNewColour(bankBackText, bankText, bankBlurText, bankBlurText2);
    setNewColour(nullptr, waveText, waveBlurText, waveBlurText2);
    setNewColour(shapeBackText, shapeText, shapeBlurText, shapeBlurText2);
    setNewColour(nullptr, shapeDepthText, shapeDepthBlurText, shapeDepthBlurText2);
    setNewColour(enhanceBackText, enhanceText, enhanceBlurText, enhanceBlurText2);
    setNewColour(nullptr, enhanceDepthText, enhanceDepthBlurText, enhanceDepthBlurText2);
    setNewColour(syncBackText, syncText, syncBlurText, syncBlurText2);
}

void TerrorformWidget::exportWavetables() {
    Terrorform* tform = dynamic_cast<Terrorform*>(module);
    std::fstream outFile;

    const char FILE_FILTERS[] = "Valley Wavetable ROM(.vwt):vwt";
    std::string dir = asset::user("");
    std::string filename;
    std::string filepath;

    osdialog_filters* filters = osdialog_filters_parse(FILE_FILTERS);
    DEFER({
        osdialog_filters_free(filters);
    });

    char* path = osdialog_file(OSDIALOG_SAVE, dir.c_str(), filename.c_str(), filters);
    if (path) {
        filepath = std::string(path);
        DEFER({
            std::free(path);
        });
    }
    else {
        return;
    }

    // Mark empty banks in new table sizes array
    char userWaveTableSizes[TFORM_MAX_BANKS];
    memcpy(&userWaveTableSizes, &tform->userWaveTableSizes, sizeof(char) * TFORM_MAX_BANKS);
    for (int b = 0; b < TFORM_MAX_BANKS; ++b) {
        userWaveTableSizes[b] = tform->userWaveTableFilled[b] ? userWaveTableSizes[b] : 0;
    }

    /** Write data to file, first the header and size, then the names, and then finally the
    data itself.
    */
    outFile.open(filepath, std::ios::out | std::ios::binary);
    if (outFile.is_open()) {
        outFile.seekp(0);
        outFile.write("T401VWT", sizeof(char) * 7);
        outFile.write(&tform->numUserWaveTables, sizeof(char));
        outFile.write((char*) &userWaveTableSizes, sizeof(char) * TFORM_MAX_BANKS);

        for (int b = 0; b < TFORM_MAX_BANKS; ++b) {
            for (unsigned long j = 0; j < tform->userWaveTableNames[b].size(); ++j) {
                outFile.write(reinterpret_cast<char*>(&tform->userWaveTableNames[b][j]), sizeof(char));
            }
            outFile.put('\0');
        }

        for (int b = 0; b < TFORM_MAX_BANKS; ++b) {
            for (int w = 0; w < TFORM_MAX_NUM_WAVES; ++w) {
                for (int j = 0; j < TFORM_MAX_WAVELENGTH; ++j) {
                    outFile.write(reinterpret_cast<char*>(&tform->userWaveTableData[b][w][j]), sizeof(float));
                }
            }
        }
    }
    outFile.close();
}

void TerrorformWidget::importWavetables() {
    Terrorform* tform = dynamic_cast<Terrorform*>(module);
    std::fstream inFile;

    const char FILE_FILTERS[] = "Valley Wavetable (.vwt):vwt";
    std::string dir = asset::user("");
    std::string filename;
    std::string filepath;

    osdialog_filters* filters = osdialog_filters_parse(FILE_FILTERS);
    DEFER({
        osdialog_filters_free(filters);
    });

    char* path = osdialog_file(OSDIALOG_OPEN, dir.c_str(), filename.c_str(), filters);
    if (path) {
        filepath = std::string(path);
        DEFER({
            std::free(path);
        });
    }
    else {
        return;
    }

    char header[8];
    int pos = 0;
    inFile.open(filepath, std::ios::in | std::ios::binary);

    if (!inFile.is_open()) {
        printf("Error opening wavetable ROM\n");
        return;
    }

    inFile.read((char*) &header, sizeof(char) * 7);
    header[7] = '\0';
    if (std::string(header) != "T401VWT") {
        printf("Not a valid Valley Wavetable ROM\n");
        return;
    }
    pos += sizeof(char) * 7;

    // Get number of tables and their respective sizes
    inFile.seekg(pos);
    inFile.read(&tform->numUserWaveTables, sizeof(char));
    inFile.read((char*) &tform->userWaveTableSizes, sizeof(char) * TFORM_MAX_BANKS);
    pos += sizeof(char) * TFORM_MAX_BANKS;

    for (int b = 0; b < TFORM_MAX_BANKS; ++b) {
        tform->userWaveTableFilled[b] = true;
        if (tform->userWaveTableSizes[b] == 0) {
            tform->userWaveTableSizes[b] = 1;
            tform->userWaveTableFilled[b] = false;
        }
    }

    // Read in wavetable names (probably not the CS way but it gets around pesky memory errors)
    tform->userWaveTableNames.clear();
    char letter = ' ';
    std::string name;
    for (int b = 0; b < TFORM_MAX_BANKS; ++b) {
        name.clear();
        letter = ' ';
        while (letter != '\0') {
            letter = inFile.get();
            name.push_back(letter);
        }
        tform->userWaveTableNames.push_back(name);
    }

    // Read in the wavetable data
    for (int b = 0; b < TFORM_MAX_BANKS; ++b) {
        for (int w = 0; w < TFORM_MAX_NUM_WAVES; ++w) {
            for (int j = 0; j < TFORM_MAX_WAVELENGTH; ++j) {
                inFile.read(reinterpret_cast<char*>(&tform->userWaveTableData[b][w][j]), sizeof(float));
            }
        }
    }

    inFile.close();
    printf("Wavetable import successful\n");
    updateBankNames = true;
}

Model *modelTerrorform = createModel<Terrorform, TerrorformWidget>("Terrorform");
