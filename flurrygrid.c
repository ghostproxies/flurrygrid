#include <stdint.h>

struct flurrygrid_state {
  uint64_t output[4];
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};

void flurrygrid(struct flurrygrid_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 1111111111111111;
  s->output[0] = s->a + s->c;
  s->c = ((s->c << 47) | (s->c >> 17)) + s->a;
  s->output[1] = ((s->a + s->b) ^ s->a) + s->c;
  s->output[2] = ((s->a << 37) | (s->a >> 27)) + s->d;
  s->d = ((s->d << 25) | (s->d >> 39)) + s->a;
  s->output[3] = (s->a ^ s->c) + s->d;
}
