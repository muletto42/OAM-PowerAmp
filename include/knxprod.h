#pragma once


#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                         (time & 0x3FFF) * 3600000 ) : 0 )
                                             
#define MAIN_OpenKnxId 0xAF
#define MAIN_ApplicationNumber 42
#define MAIN_ApplicationVersion 4
#define MAIN_ParameterSize 261
#define MAIN_MaxKoNumber 131
#define MAIN_OrderNumber "PowerAmp"
#define BASE_ModuleVersion 20
#define SWA_ModuleVersion 1
// Parameter with single occurrence


#define BASE_StartupDelayBase                     0      // 2 Bits, Bit 7-6
#define     BASE_StartupDelayBaseMask 0xC0
#define     BASE_StartupDelayBaseShift 6
#define BASE_StartupDelayTime                     0      // 14 Bits, Bit 13-0
#define     BASE_StartupDelayTimeMask 0x3FFF
#define     BASE_StartupDelayTimeShift 0
#define BASE_HeartbeatDelayBase                   2      // 2 Bits, Bit 7-6
#define     BASE_HeartbeatDelayBaseMask 0xC0
#define     BASE_HeartbeatDelayBaseShift 6
#define BASE_HeartbeatDelayTime                   2      // 14 Bits, Bit 13-0
#define     BASE_HeartbeatDelayTimeMask 0x3FFF
#define     BASE_HeartbeatDelayTimeShift 0
#define BASE_Timezone                             4      // 5 Bits, Bit 7-3
#define     BASE_TimezoneMask 0xF8
#define     BASE_TimezoneShift 3
#define BASE_CombinedTimeDate                     4      // 1 Bit, Bit 2
#define     BASE_CombinedTimeDateMask 0x04
#define     BASE_CombinedTimeDateShift 2
#define BASE_SummertimeAll                        4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeAllMask 0x03
#define     BASE_SummertimeAllShift 0
#define BASE_SummertimeDE                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeDEMask 0x03
#define     BASE_SummertimeDEShift 0
#define BASE_SummertimeWorld                      4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeWorldMask 0x03
#define     BASE_SummertimeWorldShift 0
#define BASE_SummertimeKO                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeKOMask 0x03
#define     BASE_SummertimeKOShift 0
#define BASE_TimezoneCustom                       5      // char*, 63 Byte
#define BASE_Latitude                            69      // float
#define BASE_Longitude                           73      // float
#define BASE_Diagnose                            78      // 1 Bit, Bit 7
#define     BASE_DiagnoseMask 0x80
#define     BASE_DiagnoseShift 7
#define BASE_Watchdog                            78      // 1 Bit, Bit 6
#define     BASE_WatchdogMask 0x40
#define     BASE_WatchdogShift 6
#define BASE_ReadTimeDate                        78      // 1 Bit, Bit 5
#define     BASE_ReadTimeDateMask 0x20
#define     BASE_ReadTimeDateShift 5
#define BASE_HeartbeatExtended                   78      // 1 Bit, Bit 4
#define     BASE_HeartbeatExtendedMask 0x10
#define     BASE_HeartbeatExtendedShift 4
#define BASE_InternalTime                        78      // 1 Bit, Bit 3
#define     BASE_InternalTimeMask 0x08
#define     BASE_InternalTimeShift 3
#define BASE_ManualSave                          78      // 3 Bits, Bit 2-0
#define     BASE_ManualSaveMask 0x07
#define     BASE_ManualSaveShift 0
#define BASE_PeriodicSave                        79      // 8 Bits, Bit 7-0
#define BASE_Dummy                               109      // uint8_t

// Zeitbasis
#define ParamBASE_StartupDelayBase                    ((knx.paramByte(BASE_StartupDelayBase) & BASE_StartupDelayBaseMask) >> BASE_StartupDelayBaseShift)
// Zeit
#define ParamBASE_StartupDelayTime                    (knx.paramWord(BASE_StartupDelayTime) & BASE_StartupDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamBASE_StartupDelayTimeMS                  (paramDelay(knx.paramWord(BASE_StartupDelayTime)))
// Zeitbasis
#define ParamBASE_HeartbeatDelayBase                  ((knx.paramByte(BASE_HeartbeatDelayBase) & BASE_HeartbeatDelayBaseMask) >> BASE_HeartbeatDelayBaseShift)
// Zeit
#define ParamBASE_HeartbeatDelayTime                  (knx.paramWord(BASE_HeartbeatDelayTime) & BASE_HeartbeatDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamBASE_HeartbeatDelayTimeMS                (paramDelay(knx.paramWord(BASE_HeartbeatDelayTime)))
// Zeitzone
#define ParamBASE_Timezone                            ((knx.paramByte(BASE_Timezone) & BASE_TimezoneMask) >> BASE_TimezoneShift)
// Empfangen über
#define ParamBASE_CombinedTimeDate                    ((bool)(knx.paramByte(BASE_CombinedTimeDate) & BASE_CombinedTimeDateMask))
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeAll                       (knx.paramByte(BASE_SummertimeAll) & BASE_SummertimeAllMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeDE                        (knx.paramByte(BASE_SummertimeDE) & BASE_SummertimeDEMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeWorld                     (knx.paramByte(BASE_SummertimeWorld) & BASE_SummertimeWorldMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeKO                        (knx.paramByte(BASE_SummertimeKO) & BASE_SummertimeKOMask)
// POSIX TZ-String
#define ParamBASE_TimezoneCustom                      (knx.paramData(BASE_TimezoneCustom))
// Breitengrad
#define ParamBASE_Latitude                            (knx.paramFloat(BASE_Latitude, Float_Enc_IEEE754Single))
// Längengrad
#define ParamBASE_Longitude                           (knx.paramFloat(BASE_Longitude, Float_Enc_IEEE754Single))
// Diagnoseobjekt anzeigen
#define ParamBASE_Diagnose                            ((bool)(knx.paramByte(BASE_Diagnose) & BASE_DiagnoseMask))
// Watchdog aktivieren
#define ParamBASE_Watchdog                            ((bool)(knx.paramByte(BASE_Watchdog) & BASE_WatchdogMask))
// Bei Neustart vom Bus lesen
#define ParamBASE_ReadTimeDate                        ((bool)(knx.paramByte(BASE_ReadTimeDate) & BASE_ReadTimeDateMask))
// Erweitertes "In Betrieb"
#define ParamBASE_HeartbeatExtended                   ((bool)(knx.paramByte(BASE_HeartbeatExtended) & BASE_HeartbeatExtendedMask))
// InternalTime
#define ParamBASE_InternalTime                        ((bool)(knx.paramByte(BASE_InternalTime) & BASE_InternalTimeMask))
// Manuelles speichern
#define ParamBASE_ManualSave                          (knx.paramByte(BASE_ManualSave) & BASE_ManualSaveMask)
// Zyklisches speichern
#define ParamBASE_PeriodicSave                        (knx.paramByte(BASE_PeriodicSave))
// 
#define ParamBASE_Dummy                               (knx.paramByte(BASE_Dummy))

#define BASE_KoHeartbeat 1
#define BASE_KoTime 2
#define BASE_KoDate 3
#define BASE_KoDateTime 4
#define BASE_KoIsSummertime 5
#define BASE_KoManualSave 6
#define BASE_KoDiagnose 7

// In Betrieb
#define KoBASE_Heartbeat                           (knx.getGroupObject(BASE_KoHeartbeat))
// Uhrzeit
#define KoBASE_Time                                (knx.getGroupObject(BASE_KoTime))
// Datum
#define KoBASE_Date                                (knx.getGroupObject(BASE_KoDate))
// Uhrzeit/Datum
#define KoBASE_DateTime                            (knx.getGroupObject(BASE_KoDateTime))
// Sommerzeit aktiv
#define KoBASE_IsSummertime                        (knx.getGroupObject(BASE_KoIsSummertime))
// Speichern
#define KoBASE_ManualSave                          (knx.getGroupObject(BASE_KoManualSave))
// Diagnose
#define KoBASE_Diagnose                            (knx.getGroupObject(BASE_KoDiagnose))

#define AMP_VisibleChannels                     110      // uint8_t

// Verfügbare Kanäle
#define ParamAMP_VisibleChannels                     (knx.paramByte(AMP_VisibleChannels))

#define AMP_ChannelCount 1

// Parameter per channel
#define AMP_ParamBlockOffset 111
#define AMP_ParamBlockSize 1
#define AMP_ParamCalcIndex(index) (index + AMP_ParamBlockOffset + _channelIndex * AMP_ParamBlockSize)

#define AMP_ChActive                             0      // 2 Bits, Bit 7-6
#define     AMP_ChActiveMask 0xC0
#define     AMP_ChActiveShift 6
#define AMP_Source                               0      // 8 Bits, Bit 7-0
#define AMP_VolumeDay                            0      // uint8_t
#define AMP_VolumeNight                          0      // uint8_t
#define AMP_mute                                 0      // 1 Bit, Bit 7
#define     AMP_muteMask 0x80
#define     AMP_muteShift 7
#define AMP_DayNight                             0      // 2 Bits, Bit 7-6
#define     AMP_DayNightMask 0xC0
#define     AMP_DayNightShift 6
#define AMP_Lock                                 0      // 2 Bits, Bit 7-6
#define     AMP_LockMask 0xC0
#define     AMP_LockShift 6

// Kanalaktivität
#define ParamAMP_ChActive                            ((knx.paramByte(AMP_ParamCalcIndex(AMP_ChActive)) & AMP_ChActiveMask) >> AMP_ChActiveShift)
// Quelle
#define ParamAMP_Source                              (knx.paramByte(AMP_ParamCalcIndex(AMP_Source)))
// 
#define ParamAMP_VolumeDay                           (knx.paramByte(AMP_ParamCalcIndex(AMP_VolumeDay)))
// 
#define ParamAMP_VolumeNight                         (knx.paramByte(AMP_ParamCalcIndex(AMP_VolumeNight)))
// Mute
#define ParamAMP_mute                                ((bool)(knx.paramByte(AMP_ParamCalcIndex(AMP_mute)) & AMP_muteMask))
// Tag/Nacht-Objekt
#define ParamAMP_DayNight                            ((knx.paramByte(AMP_ParamCalcIndex(AMP_DayNight)) & AMP_DayNightMask) >> AMP_DayNightShift)
// Zentrale Sperre
#define ParamAMP_Lock                                ((knx.paramByte(AMP_ParamCalcIndex(AMP_Lock)) & AMP_LockMask) >> AMP_LockShift)

// deprecated
#define AMP_KoOffset 25

// Communication objects per channel (multiple occurrence)
#define AMP_KoBlockOffset 25
#define AMP_KoBlockSize 17

#define AMP_KoCalcNumber(index) (index + AMP_KoBlockOffset + _channelIndex * AMP_KoBlockSize)
#define AMP_KoCalcIndex(number) ((number >= AMP_KoCalcNumber(0) && number < AMP_KoCalcNumber(AMP_KoBlockSize)) ? (number - AMP_KoBlockOffset) % AMP_KoBlockSize : -1)
#define AMP_KoCalcChannel(number) ((number >= AMP_KoBlockOffset && number < AMP_KoBlockOffset + AMP_ChannelCount * AMP_KoBlockSize) ? (number - AMP_KoBlockOffset) / AMP_KoBlockSize : -1)

#define AMP_Kovolume_value 1
#define AMP_Kovolume_inc 2
#define AMP_Kovolume_dec 3
#define AMP_Kosource 4
#define AMP_Komute_onoff 5
#define AMP_KoPlayPause 6
#define AMP_KoStop 7
#define AMP_KoNext 8
#define AMP_KoPrev 9
#define AMP_KoDayNight 10
#define AMP_KoScene 11
#define AMP_KoLock 12
#define AMP_KoChsongMetadataTitle 13
#define AMP_KoChsongMetadataAlbum 14
#define AMP_KoChsongMetadataArtist 15
#define AMP_KoChsongMetadataVendor 16
#define AMP_Kovolume_Status 17

// Lautstärke Amp %Z%
#define KoAMP_volume_value                        (knx.getGroupObject(AMP_KoCalcNumber(AMP_Kovolume_value)))
// Lautstärke Amp %Z%
#define KoAMP_volume_inc                          (knx.getGroupObject(AMP_KoCalcNumber(AMP_Kovolume_inc)))
// Lautstärke Amp %Z%
#define KoAMP_volume_dec                          (knx.getGroupObject(AMP_KoCalcNumber(AMP_Kovolume_dec)))
// Quelle Amp %Z%
#define KoAMP_source                              (knx.getGroupObject(AMP_KoCalcNumber(AMP_Kosource)))
// Mute Amp %Z%
#define KoAMP_mute_onoff                          (knx.getGroupObject(AMP_KoCalcNumber(AMP_Komute_onoff)))
// Track Amp %Z%
#define KoAMP_PlayPause                           (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoPlayPause)))
// Track Amp %Z%
#define KoAMP_Stop                                (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoStop)))
// Track Amp %Z%
#define KoAMP_Next                                (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoNext)))
// Track Amp %Z%
#define KoAMP_Prev                                (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoPrev)))
// TagNacht %Z%
#define KoAMP_DayNight                            (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoDayNight)))
// Szene %Z%
#define KoAMP_Scene                               (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoScene)))
// Lock %Z%
#define KoAMP_Lock                                (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoLock)))
// 
#define KoAMP_ChsongMetadataTitle                 (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoChsongMetadataTitle)))
// 
#define KoAMP_ChsongMetadataAlbum                 (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoChsongMetadataAlbum)))
// 
#define KoAMP_ChsongMetadataArtist                (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoChsongMetadataArtist)))
// 
#define KoAMP_ChsongMetadataVendor                (knx.getGroupObject(AMP_KoCalcNumber(AMP_KoChsongMetadataVendor)))
// Lautstärke Status Amp %Z%
#define KoAMP_volume_Status                       (knx.getGroupObject(AMP_KoCalcNumber(AMP_Kovolume_Status)))

#define SWA_VisibleChannels                     112      // uint8_t

// Verfügbare Kanäle
#define ParamSWA_VisibleChannels                     (knx.paramByte(SWA_VisibleChannels))

#define SWA_KoCentralFunction 100

// Zentralfunktion
#define KoSWA_CentralFunction                     (knx.getGroupObject(SWA_KoCentralFunction))

#define SWA_ChannelCount 2

// Parameter per channel
#define SWA_ParamBlockOffset 113
#define SWA_ParamBlockSize 74
#define SWA_ParamCalcIndex(index) (index + SWA_ParamBlockOffset + _channelIndex * SWA_ParamBlockSize)

#define SWA_ChActive                             0      // 2 Bits, Bit 7-6
#define     SWA_ChActiveMask 0xC0
#define     SWA_ChActiveShift 6
#define SWA_ChSyncSwitch                         0      // 1 Bit, Bit 5
#define     SWA_ChSyncSwitchMask 0x20
#define     SWA_ChSyncSwitchShift 5
#define SWA_ChOperationMode                      0      // 1 Bit, Bit 4
#define     SWA_ChOperationModeMask 0x10
#define     SWA_ChOperationModeShift 4
#define SWA_ChCentralFunction                    0      // 1 Bit, Bit 3
#define     SWA_ChCentralFunctionMask 0x08
#define     SWA_ChCentralFunctionShift 3
#define SWA_ChStatusSend                         0      // 2 Bits, Bit 2-1
#define     SWA_ChStatusSendMask 0x06
#define     SWA_ChStatusSendShift 1
#define SWA_ChStatusInverted                     0      // 1 Bit, Bit 0
#define     SWA_ChStatusInvertedMask 0x01
#define     SWA_ChStatusInvertedShift 0
#define SWA_ChTurnOnDelayBase                    1      // 2 Bits, Bit 7-6
#define     SWA_ChTurnOnDelayBaseMask 0xC0
#define     SWA_ChTurnOnDelayBaseShift 6
#define SWA_ChTurnOnDelayTime                    1      // 14 Bits, Bit 13-0
#define     SWA_ChTurnOnDelayTimeMask 0x3FFF
#define     SWA_ChTurnOnDelayTimeShift 0
#define SWA_ChTurnOffDelayBase                   3      // 2 Bits, Bit 7-6
#define     SWA_ChTurnOffDelayBaseMask 0xC0
#define     SWA_ChTurnOffDelayBaseShift 6
#define SWA_ChTurnOffDelayTime                   3      // 14 Bits, Bit 13-0
#define     SWA_ChTurnOffDelayTimeMask 0x3FFF
#define     SWA_ChTurnOffDelayTimeShift 0
#define SWA_ChStatusCyclicBase                   5      // 2 Bits, Bit 7-6
#define     SWA_ChStatusCyclicBaseMask 0xC0
#define     SWA_ChStatusCyclicBaseShift 6
#define SWA_ChStatusCyclicTime                   5      // 14 Bits, Bit 13-0
#define     SWA_ChStatusCyclicTimeMask 0x3FFF
#define     SWA_ChStatusCyclicTimeShift 0
#define SWA_ChBehaviorLock                       7      // 2 Bits, Bit 7-6
#define     SWA_ChBehaviorLockMask 0xC0
#define     SWA_ChBehaviorLockShift 6
#define SWA_ChBehaviorUnlock                     7      // 3 Bits, Bit 5-3
#define     SWA_ChBehaviorUnlockMask 0x38
#define     SWA_ChBehaviorUnlockShift 3
#define SWA_ChBehaviorPowerLoss                  8      // 2 Bits, Bit 7-6
#define     SWA_ChBehaviorPowerLossMask 0xC0
#define     SWA_ChBehaviorPowerLossShift 6
#define SWA_ChBehaviorPowerRegain                8      // 2 Bits, Bit 5-4
#define     SWA_ChBehaviorPowerRegainMask 0x30
#define     SWA_ChBehaviorPowerRegainShift 4
#define SWA_ChStairLightActive                   9      // 1 Bit, Bit 7
#define     SWA_ChStairLightActiveMask 0x80
#define     SWA_ChStairLightActiveShift 7
#define SWA_ChScenesActive                       9      // 1 Bit, Bit 6
#define     SWA_ChScenesActiveMask 0x40
#define     SWA_ChScenesActiveShift 6
#define SWA_ChSceneLearn                         9      // 1 Bit, Bit 0
#define     SWA_ChSceneLearnMask 0x01
#define     SWA_ChSceneLearnShift 0
#define SWA_ChStairTimeBase                     10      // 2 Bits, Bit 7-6
#define     SWA_ChStairTimeBaseMask 0xC0
#define     SWA_ChStairTimeBaseShift 6
#define SWA_ChStairTimeTime                     10      // 14 Bits, Bit 13-0
#define     SWA_ChStairTimeTimeMask 0x3FFF
#define     SWA_ChStairTimeTimeShift 0
#define SWA_ChStairRetrigger                    12      // 1 Bit, Bit 7
#define     SWA_ChStairRetriggerMask 0x80
#define     SWA_ChStairRetriggerShift 7
#define SWA_ChStairOff                          12      // 1 Bit, Bit 6
#define     SWA_ChStairOffMask 0x40
#define     SWA_ChStairOffShift 6
#define SWA_ChStairBlinkBase                    13      // 2 Bits, Bit 7-6
#define     SWA_ChStairBlinkBaseMask 0xC0
#define     SWA_ChStairBlinkBaseShift 6
#define SWA_ChStairBlinkTime                    13      // 14 Bits, Bit 13-0
#define     SWA_ChStairBlinkTimeMask 0x3FFF
#define     SWA_ChStairBlinkTimeShift 0
#define SWA_ChSceneAActive                      58      // 1 Bit, Bit 7
#define     SWA_ChSceneAActiveMask 0x80
#define     SWA_ChSceneAActiveShift 7
#define SWA_ChSceneABehavior                    58      // 2 Bits, Bit 6-5
#define     SWA_ChSceneABehaviorMask 0x60
#define     SWA_ChSceneABehaviorShift 5
#define SWA_ChSceneANumber                      59      // 8 Bits, Bit 7-0
#define SWA_ChSceneBActive                      60      // 1 Bit, Bit 7
#define     SWA_ChSceneBActiveMask 0x80
#define     SWA_ChSceneBActiveShift 7
#define SWA_ChSceneBBehavior                    60      // 2 Bits, Bit 6-5
#define     SWA_ChSceneBBehaviorMask 0x60
#define     SWA_ChSceneBBehaviorShift 5
#define SWA_ChSceneBNumber                      61      // 8 Bits, Bit 7-0
#define SWA_ChSceneCActive                      62      // 1 Bit, Bit 7
#define     SWA_ChSceneCActiveMask 0x80
#define     SWA_ChSceneCActiveShift 7
#define SWA_ChSceneCBehavior                    62      // 2 Bits, Bit 6-5
#define     SWA_ChSceneCBehaviorMask 0x60
#define     SWA_ChSceneCBehaviorShift 5
#define SWA_ChSceneCNumber                      63      // 8 Bits, Bit 7-0
#define SWA_ChSceneDActive                      64      // 1 Bit, Bit 7
#define     SWA_ChSceneDActiveMask 0x80
#define     SWA_ChSceneDActiveShift 7
#define SWA_ChSceneDBehavior                    64      // 2 Bits, Bit 6-5
#define     SWA_ChSceneDBehaviorMask 0x60
#define     SWA_ChSceneDBehaviorShift 5
#define SWA_ChSceneDNumber                      65      // 8 Bits, Bit 7-0
#define SWA_ChSceneEActive                      66      // 1 Bit, Bit 7
#define     SWA_ChSceneEActiveMask 0x80
#define     SWA_ChSceneEActiveShift 7
#define SWA_ChSceneEBehavior                    66      // 2 Bits, Bit 6-5
#define     SWA_ChSceneEBehaviorMask 0x60
#define     SWA_ChSceneEBehaviorShift 5
#define SWA_ChSceneENumber                      67      // 8 Bits, Bit 7-0
#define SWA_ChSceneFActive                      68      // 1 Bit, Bit 7
#define     SWA_ChSceneFActiveMask 0x80
#define     SWA_ChSceneFActiveShift 7
#define SWA_ChSceneFBehavior                    68      // 2 Bits, Bit 6-5
#define     SWA_ChSceneFBehaviorMask 0x60
#define     SWA_ChSceneFBehaviorShift 5
#define SWA_ChSceneFNumber                      69      // 8 Bits, Bit 7-0
#define SWA_ChSceneGActive                      70      // 1 Bit, Bit 7
#define     SWA_ChSceneGActiveMask 0x80
#define     SWA_ChSceneGActiveShift 7
#define SWA_ChSceneGBehavior                    70      // 2 Bits, Bit 6-5
#define     SWA_ChSceneGBehaviorMask 0x60
#define     SWA_ChSceneGBehaviorShift 5
#define SWA_ChSceneGNumber                      71      // 8 Bits, Bit 7-0
#define SWA_ChSceneHActive                      72      // 1 Bit, Bit 7
#define     SWA_ChSceneHActiveMask 0x80
#define     SWA_ChSceneHActiveShift 7
#define SWA_ChSceneHBehavior                    72      // 2 Bits, Bit 6-5
#define     SWA_ChSceneHBehaviorMask 0x60
#define     SWA_ChSceneHBehaviorShift 5
#define SWA_ChSceneHNumber                      73      // 8 Bits, Bit 7-0

// Kanalaktivität
#define ParamSWA_ChActive                            ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChActive)) & SWA_ChActiveMask) >> SWA_ChActiveShift)
// Synchron schalten
#define ParamSWA_ChSyncSwitch                        ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSyncSwitch)) & SWA_ChSyncSwitchMask))
// Betriebsmodus
#define ParamSWA_ChOperationMode                     ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChOperationMode)) & SWA_ChOperationModeMask))
// Zentralfunktion
#define ParamSWA_ChCentralFunction                   ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChCentralFunction)) & SWA_ChCentralFunctionMask))
// Status senden
#define ParamSWA_ChStatusSend                        ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChStatusSend)) & SWA_ChStatusSendMask) >> SWA_ChStatusSendShift)
// Zusätzlicher invertierter Status
#define ParamSWA_ChStatusInverted                    ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChStatusInverted)) & SWA_ChStatusInvertedMask))
// Zeitbasis
#define ParamSWA_ChTurnOnDelayBase                   ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChTurnOnDelayBase)) & SWA_ChTurnOnDelayBaseMask) >> SWA_ChTurnOnDelayBaseShift)
// Zeit
#define ParamSWA_ChTurnOnDelayTime                   (knx.paramWord(SWA_ParamCalcIndex(SWA_ChTurnOnDelayTime)) & SWA_ChTurnOnDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamSWA_ChTurnOnDelayTimeMS                 (paramDelay(knx.paramWord(SWA_ParamCalcIndex(SWA_ChTurnOnDelayTime))))
// Zeitbasis
#define ParamSWA_ChTurnOffDelayBase                  ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChTurnOffDelayBase)) & SWA_ChTurnOffDelayBaseMask) >> SWA_ChTurnOffDelayBaseShift)
// Zeit
#define ParamSWA_ChTurnOffDelayTime                  (knx.paramWord(SWA_ParamCalcIndex(SWA_ChTurnOffDelayTime)) & SWA_ChTurnOffDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamSWA_ChTurnOffDelayTimeMS                (paramDelay(knx.paramWord(SWA_ParamCalcIndex(SWA_ChTurnOffDelayTime))))
// Zeitbasis
#define ParamSWA_ChStatusCyclicBase                  ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChStatusCyclicBase)) & SWA_ChStatusCyclicBaseMask) >> SWA_ChStatusCyclicBaseShift)
// Zeit
#define ParamSWA_ChStatusCyclicTime                  (knx.paramWord(SWA_ParamCalcIndex(SWA_ChStatusCyclicTime)) & SWA_ChStatusCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamSWA_ChStatusCyclicTimeMS                (paramDelay(knx.paramWord(SWA_ParamCalcIndex(SWA_ChStatusCyclicTime))))
// bei Sperren
#define ParamSWA_ChBehaviorLock                      ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChBehaviorLock)) & SWA_ChBehaviorLockMask) >> SWA_ChBehaviorLockShift)
// bei Entsperren
#define ParamSWA_ChBehaviorUnlock                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChBehaviorUnlock)) & SWA_ChBehaviorUnlockMask) >> SWA_ChBehaviorUnlockShift)
// bei Busspannungsverlust
#define ParamSWA_ChBehaviorPowerLoss                 ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChBehaviorPowerLoss)) & SWA_ChBehaviorPowerLossMask) >> SWA_ChBehaviorPowerLossShift)
// bei Busspannungswiederkehr
#define ParamSWA_ChBehaviorPowerRegain               ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChBehaviorPowerRegain)) & SWA_ChBehaviorPowerRegainMask) >> SWA_ChBehaviorPowerRegainShift)
// Treppenlicht aktivieren
#define ParamSWA_ChStairLightActive                  ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChStairLightActive)) & SWA_ChStairLightActiveMask))
// Szenen aktivieren
#define ParamSWA_ChScenesActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChScenesActive)) & SWA_ChScenesActiveMask))
// Szene lernen
#define ParamSWA_ChSceneLearn                        ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneLearn)) & SWA_ChSceneLearnMask))
// Zeit für Treppenlicht
#define ParamSWA_ChStairTimeBase                     ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChStairTimeBase)) & SWA_ChStairTimeBaseMask) >> SWA_ChStairTimeBaseShift)
// Zeit für Treppenlicht
#define ParamSWA_ChStairTimeTime                     (knx.paramWord(SWA_ParamCalcIndex(SWA_ChStairTimeTime)) & SWA_ChStairTimeTimeMask)
// Zeit für Treppenlicht (in Millisekunden)
#define ParamSWA_ChStairTimeTimeMS                   (paramDelay(knx.paramWord(SWA_ParamCalcIndex(SWA_ChStairTimeTime))))
// Treppenlicht kann verlängert werden
#define ParamSWA_ChStairRetrigger                    ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChStairRetrigger)) & SWA_ChStairRetriggerMask))
// Treppenlicht kann ausgeschaltet werden
#define ParamSWA_ChStairOff                          ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChStairOff)) & SWA_ChStairOffMask))
// Treppenlicht blinkt im Rhythmus
#define ParamSWA_ChStairBlinkBase                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChStairBlinkBase)) & SWA_ChStairBlinkBaseMask) >> SWA_ChStairBlinkBaseShift)
// Treppenlicht blinkt im Rhythmus
#define ParamSWA_ChStairBlinkTime                    (knx.paramWord(SWA_ParamCalcIndex(SWA_ChStairBlinkTime)) & SWA_ChStairBlinkTimeMask)
// Treppenlicht blinkt im Rhythmus (in Millisekunden)
#define ParamSWA_ChStairBlinkTimeMS                  (paramDelay(knx.paramWord(SWA_ParamCalcIndex(SWA_ChStairBlinkTime))))
// Szene aktiv
#define ParamSWA_ChSceneAActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneAActive)) & SWA_ChSceneAActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneABehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneABehavior)) & SWA_ChSceneABehaviorMask) >> SWA_ChSceneABehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneANumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneANumber)))
// Szene aktiv
#define ParamSWA_ChSceneBActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneBActive)) & SWA_ChSceneBActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneBBehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneBBehavior)) & SWA_ChSceneBBehaviorMask) >> SWA_ChSceneBBehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneBNumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneBNumber)))
// Szene aktiv
#define ParamSWA_ChSceneCActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneCActive)) & SWA_ChSceneCActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneCBehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneCBehavior)) & SWA_ChSceneCBehaviorMask) >> SWA_ChSceneCBehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneCNumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneCNumber)))
// Szene aktiv
#define ParamSWA_ChSceneDActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneDActive)) & SWA_ChSceneDActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneDBehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneDBehavior)) & SWA_ChSceneDBehaviorMask) >> SWA_ChSceneDBehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneDNumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneDNumber)))
// Szene aktiv
#define ParamSWA_ChSceneEActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneEActive)) & SWA_ChSceneEActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneEBehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneEBehavior)) & SWA_ChSceneEBehaviorMask) >> SWA_ChSceneEBehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneENumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneENumber)))
// Szene aktiv
#define ParamSWA_ChSceneFActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneFActive)) & SWA_ChSceneFActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneFBehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneFBehavior)) & SWA_ChSceneFBehaviorMask) >> SWA_ChSceneFBehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneFNumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneFNumber)))
// Szene aktiv
#define ParamSWA_ChSceneGActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneGActive)) & SWA_ChSceneGActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneGBehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneGBehavior)) & SWA_ChSceneGBehaviorMask) >> SWA_ChSceneGBehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneGNumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneGNumber)))
// Szene aktiv
#define ParamSWA_ChSceneHActive                      ((bool)(knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneHActive)) & SWA_ChSceneHActiveMask))
// Szene Verhalten
#define ParamSWA_ChSceneHBehavior                    ((knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneHBehavior)) & SWA_ChSceneHBehaviorMask) >> SWA_ChSceneHBehaviorShift)
// Szene Nummer
#define ParamSWA_ChSceneHNumber                      (knx.paramByte(SWA_ParamCalcIndex(SWA_ChSceneHNumber)))

// deprecated
#define SWA_KoOffset 120

// Communication objects per channel (multiple occurrence)
#define SWA_KoBlockOffset 120
#define SWA_KoBlockSize 6

#define SWA_KoCalcNumber(index) (index + SWA_KoBlockOffset + _channelIndex * SWA_KoBlockSize)
#define SWA_KoCalcIndex(number) ((number >= SWA_KoCalcNumber(0) && number < SWA_KoCalcNumber(SWA_KoBlockSize)) ? (number - SWA_KoBlockOffset) % SWA_KoBlockSize : -1)
#define SWA_KoCalcChannel(number) ((number >= SWA_KoBlockOffset && number < SWA_KoBlockOffset + SWA_ChannelCount * SWA_KoBlockSize) ? (number - SWA_KoBlockOffset) / SWA_KoBlockSize : -1)

#define SWA_KoChSwitch 0
#define SWA_KoChStatus 1
#define SWA_KoChStatusInverted 2
#define SWA_KoChLock 3
#define SWA_KoChLockStatus 4
#define SWA_KoChScene 5

// 
#define KoSWA_ChSwitch                            (knx.getGroupObject(SWA_KoCalcNumber(SWA_KoChSwitch)))
// 
#define KoSWA_ChStatus                            (knx.getGroupObject(SWA_KoCalcNumber(SWA_KoChStatus)))
// 
#define KoSWA_ChStatusInverted                    (knx.getGroupObject(SWA_KoCalcNumber(SWA_KoChStatusInverted)))
// 
#define KoSWA_ChLock                              (knx.getGroupObject(SWA_KoCalcNumber(SWA_KoChLock)))
// 
#define KoSWA_ChLockStatus                        (knx.getGroupObject(SWA_KoCalcNumber(SWA_KoChLockStatus)))
// 
#define KoSWA_ChScene                             (knx.getGroupObject(SWA_KoCalcNumber(SWA_KoChScene)))



// Header generation for Module 'BASE_KommentarModule'

#define BASE_KommentarModuleCount 0
#define BASE_KommentarModuleModuleParamSize 0
#define BASE_KommentarModuleSubmodulesParamSize 0
#define BASE_KommentarModuleParamSize 0
#define BASE_KommentarModuleParamOffset 261
#define BASE_KommentarModuleCalcIndex(index, m1) (index + BASE_KommentarModuleParamOffset + _channelIndex * BASE_KommentarModuleCount * BASE_KommentarModuleParamSize + m1 * BASE_KommentarModuleParamSize)



