/**
 *   @file  mmwdemo_rfparser.h
 *
 *   @brief
 *      Header file for RF configuration parser
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2018 Texas Instruments, Inc.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef MMWDEMO_RFPARSER_H
#define MMWDEMO_RFPARSER_H

#include <ti/drivers/adcbuf/ADCBuf.h>
#include <ti/control/mmwave/mmwave.h>
#include "mmwdemo_adcconfig.h"
#include <ti/demo/utils/mmwdemo_error.h>


/** @defgroup MMWDEMO_RFPARSER_EXTERNAL       Mmwdemo RFparser External
 */

/**
@defgroup MMWDEMO_RFPARSER_EXTERNAL_FUNCTION            RF Parser External Functions
@ingroup MMWDEMO_RFPARSER_EXTERNAL
@brief
*   The section has a list of all the exported API which the applications need to
*   invoke in order to use the RF Parser
*/
/**
@defgroup MMWDEMO_RFPARSER_EXTERNAL_DATA_STRUCTURE      RF Parser External Data Structures
@ingroup MMWDEMO_RFPARSER_EXTERNAL
@brief
*   The section has a list of all the data structures which are exposed to the application
*/
/**
@defgroup MMWDEMO_RFPARSER_ERROR_CODE                   RF Parser Error Codes
@ingroup MMWDEMO_RFPARSER_EXTERNAL
@brief
*   The section has a list of all the error codes which are generated by the RFParser DPU
*/

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup MMWDEMO_RFPARSER_ERROR_CODE
 @{ */

/**
 * @brief   Error Code: Invalid computed output number of tx antennas.
 */
#define MMWDEMO_RFPARSER_EINVAL_NUM_TX_ANTENNAS                   (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-1)

/**
 * @brief   Error Code: Invalid computed output number of virtual antennas.
 */
#define MMWDEMO_RFPARSER_EINVAL__NUM_VIRTUAL_ANTENNAS             (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-2)

/**
 * @brief   Error Code: Invalid subFrameIndx argument to @ref MmwDemo_RFParser_parseConfig
 */
#define MMWDEMO_RFPARSER_EINVAL__NUM_SUBFRAMES                    (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-3)

/**
 * @brief   Error Code: Chirp threshold bigger than max allowed
 */
#define MMWDEMO_RFPARSER_EINVAL__CHIRP_THRESH_GREATER_THAN_MAX_ALLOWED (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-4)

/**
 * @brief   Error Code: Not implemented parsing of number of unique chirps
 *                      (determined by chirpEndIndx and chirpStartIndx) more than 32.
 */
#define MMWDEMO_RFPARSER_ENOIMPL__NUM_UNIQUE_CHIRPS_MORE_THAN_32   (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-5)

/**
 * @brief   Error Code: Not supported non complex ADC
 */
#define MMWDEMO_RFPARSER_ENOTSUPPORT__NON_COMPLEX_ADC_FORMAT     (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-6)

/**
 * @brief   Error Code: Not supported non-16-bits ADC
 */
#define MMWDEMO_RFPARSER_ENOTSUPPORT__NON_16BITS_ADC              (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-7)

/**
 * @brief   Error Code: Not supported non one numOfBurst in Advanced fram
 */
#define MMWDEMO_RFPARSER_ENOTSUPPORT__NON_ONE_NUMOFBURST_FOR_ADVANCED_FRAME     (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-8)

/**
 * @brief   Error Code: Not supported negative frequency slope.
 */
#define MMWDEMO_RFPARSER_ENOTSUPPORT__NEGATIVE_FREQ_SLOPE         (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-9)

/**
 * @brief   Error Code: Not supported chirp threshold that is not divisible to number of chirps per frame.
 */
#define MMWDEMO_RFPARSER_ENOTSUPPORT__NON_DIVISIBILITY_OF_CHIRP_THRESH (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-10)

/**
 * @brief   Error Code: Not supported non-complex ADC format.
 */
#define MMWDEMO_RFPARSER_ENOTSUPPORT__NONCOMPLEX_ADC_FORMAT       (MMWAVE_ERRNO_MMWDEMO_RFPARSER_BASE-11)

/**
@}
*/

/**
 * @brief RF parser's output parameters structure.
 *
 * \ingroup MMWDEMO_RFPARSER_EXTERNAL_DATA_STRUCTURE
 */
typedef struct MmwDemo_RFParserOutParams_t
{
    /*! @brief valid Profile index */
    uint8_t     validProfileIdx;

    /*! @brief   1 if valid profile has one Tx per chirp else 0 */
    uint8_t     validProfileHasOneTxPerChirp;

    /*! @brief  ADCBUF will generate chirp interrupt event every this many chirps - chirpthreshold */
    uint8_t     numChirpsPerChirpEvent;

    /*! @brief  Number of ADC samples */
    uint16_t    numAdcSamples;

    /*! @brief  Number of transmit antennas */
    uint8_t     numRxAntennas;

    /*! @brief  Rx Antenna order */
    uint8_t     rxAntOrder[SYS_COMMON_NUM_RX_CHANNEL];

    /*! @brief  Tx Antenna order */
    uint8_t     txAntOrder[SYS_COMMON_NUM_TX_ANTENNAS];

    /*! @brief  Number of transmit antennas */
    uint8_t     numTxAntennas;

    /*! @brief  Number of virtual antennas */
    uint8_t     numVirtualAntennas;

    /*! @brief  Number of virtual azimuth antennas */
    uint8_t     numVirtualAntAzim;

    /*! @brief  Number of virtual elevation antennas */
    uint8_t     numVirtualAntElev;

    /*! @brief  Number of range FFT bins, this is at a minimum the next power of 2 of
                @ref numAdcSamples. If range zoom is supported, this can be bigger than
                the minimum. */
    uint16_t    numRangeBins;

    /*! @brief  Number of chirps per frame */
    uint16_t    numChirpsPerFrame;

    /*! @brief  Number of bytes per RX channel, it is aligned to 16 bytes as required by ADCBuf driver  */
    uint32_t    adcBufChanDataSize;

    /*! @brief Number of chirps for Doppler computation purposes.
               For example, in TDM/BPM-MIMO scheme, this is the physical chirps
               in a frame per transmit antenna
               i.e numDopplerChirps = @ref numChirpsPerFrame / @ref numTxAntennas */
    uint16_t    numDopplerChirps;

    /*! @brief  Number of Doppler FFT bins, this is at a minimum the next power of 2 of
                @ref numDopplerChirps. If Doppler zoom is supported, this can be bigger
                than the minimum. */
    uint16_t    numDopplerBins;

    /*! @brief  Natual range resolution in meters */
    float       rangeStep;

    /*! @brief  Natual doppler resolution in m/s  */
    float       dopplerStep;

    /*! @brief  Frame period in ms */
    float       framePeriod;

    /*! @brief  Chirp interval in ms */
    float       chirpInterval;

    /*! @brief  bandwidth */
    float       bandwidth;

    /*! @brief  center frenquency */
    float       centerFreq;
} MmwDemo_RFParserOutParams;


/***************************************************
 *  RFParserProc APIs
 ***************************************************/
extern int32_t MmwDemo_RFParser_parseConfig
(
    MmwDemo_RFParserOutParams    *outParams,
    uint8_t              subFrameIdx,
    MMWave_OpenCfg       *openCfg,
    MMWave_CtrlCfg       *ptrCtrlCfg,
    MmwDemo_ADCBufCfg    *adcBufCfg,
    float                rfFreqScaleFactor,
    bool                 bpmEnabled
);

extern uint8_t MmwDemo_RFParser_getNumSubFrames(MMWave_CtrlCfg *ctrlCfg);

#ifdef __cplusplus
}
#endif

#endif /* RFPARSER_H */
