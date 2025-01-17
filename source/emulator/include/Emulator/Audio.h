#ifndef EMULATOR_INCLUDE_EMULATOR_AUDIO_H_
#define EMULATOR_INCLUDE_EMULATOR_AUDIO_H_

#include "Kyty/Core/Common.h"
#include "Kyty/Core/Subsystems.h"

#include "Emulator/Common.h"

#ifdef KYTY_EMU_ENABLED

namespace Kyty::Libs::Audio {

KYTY_SUBSYSTEM_DEFINE(Audio);

namespace AudioOut {

struct AudioOutOutputParam;

int KYTY_SYSV_ABI AudioOutInit();
int KYTY_SYSV_ABI AudioOutOpen(int user_id, int type, int index, uint32_t len, uint32_t freq, uint32_t param);
int KYTY_SYSV_ABI AudioOutSetVolume(int handle, uint32_t flag, int* vol);
int KYTY_SYSV_ABI AudioOutOutputs(AudioOutOutputParam* param, uint32_t num);
int KYTY_SYSV_ABI AudioOutOutput(int handle, const void* ptr);
int KYTY_SYSV_ABI AudioOutClose(int handle);

} // namespace AudioOut

namespace AudioIn {

int KYTY_SYSV_ABI AudioInOpen(int user_id, uint32_t type, uint32_t index, uint32_t len, uint32_t freq, uint32_t param);
int KYTY_SYSV_ABI AudioInInput(int handle, void* dest);

} // namespace AudioIn

namespace VoiceQoS {

int KYTY_SYSV_ABI VoiceQoSInit(void* mem_block, uint32_t mem_size, int32_t app_type);

} // namespace VoiceQoS

namespace Ajm {

int KYTY_SYSV_ABI AjmInitialize(int64_t reserved, uint32_t* context);
int KYTY_SYSV_ABI AjmModuleRegister(uint32_t context, uint32_t codec, int64_t reserved);

} // namespace Ajm

namespace AvPlayer {

struct AvPlayerInitData;
struct AvPlayerFrameInfoEx;
struct AvPlayerFrameInfo;
struct AvPlayerInternal;

using Bool = uint8_t;

AvPlayerInternal* KYTY_SYSV_ABI AvPlayerInit(AvPlayerInitData* init);
int KYTY_SYSV_ABI               AvPlayerAddSource(AvPlayerInternal* h, const char* filename);
int KYTY_SYSV_ABI               AvPlayerSetLooping(AvPlayerInternal* h, Bool loop);
Bool KYTY_SYSV_ABI              AvPlayerGetVideoDataEx(AvPlayerInternal* h, AvPlayerFrameInfoEx* video_info);
Bool KYTY_SYSV_ABI              AvPlayerGetAudioData(AvPlayerInternal* h, AvPlayerFrameInfo* audio_info);
Bool KYTY_SYSV_ABI              AvPlayerIsActive(AvPlayerInternal* h);
int KYTY_SYSV_ABI               AvPlayerClose(AvPlayerInternal* h);

} // namespace AvPlayer

} // namespace Kyty::Libs::Audio

#endif // KYTY_EMU_ENABLED

#endif /* EMULATOR_INCLUDE_EMULATOR_AUDIO_H_ */
