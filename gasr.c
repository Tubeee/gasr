#include <iostream>
#include <vector>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef void (*RecognitionResultHandler)(const char*, const bool, void*);

typedef struct {
  // The channel count and sample rate of the audio stream. SODA does not
  // support changing these values mid-stream, so a new SODA instance must be
  // created if these values change.
  int channel_count;
  int sample_rate;

  // The fully-qualified path to the language pack.
  const char* language_pack_directory;

  // The callback that gets executed on a recognition event. It takes in a
  // char*, representing the transcribed text; a bool, representing whether the
  // result is final or not; and a void* pointer to the SodaRecognizerImpl
  // instance associated with the stream.
  RecognitionResultHandler callback;

  // A void pointer to the SodaRecognizerImpl instance associated with the
  // stream.
  void* callback_handle;

  const char* api_key;
} SodaConfig;

// Creates and instantiates an instance of SODA.
extern void* CreateSodaAsync(SodaConfig config);

// Destroys the instance of SODA, called on the destruction of the SodaClient.
extern void DeleteSodaAsync(void* soda_async_handle);

// Feeds raw audio to SODA in the form of a contiguous stream of characters.
extern void AddAudio(void* soda_async_handle, const char* audio_buffer, int audio_buffer_size);
}

#ifdef __cplusplus
}
#endif

using namespace std;

int main(int argc, char *argv[]) {
	return 0;
}

