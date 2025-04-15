#include <stdio.h>
#include <math.h>

#define g 9.8 // 중력가속도
#define PI 3.141592653589793 // 파이 정의

int main() {
    double v0 = 100.0;        // 초기 속도 (m/s)
    double angle_deg = 37.0;  // 발사 각도 (도)
    double y0 = 140.0;        // 초기 높이 (m)

    // 각도 라디안으로 변환
    double angle_rad = angle_deg * PI / 180.0;

    // 초기 속도의 x, y 성분
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    // 1. 착지 시간 구하기 (이차방정식의 해)
    double a = -0.5 * g;
    double b = v0y;
    double c = y0;

    double dis = b * b - 4 * a * c;
    if (dis < 0) {
        printf("해가 없습니다.\n");
        return 1;
    }

    double t1 = (-b + sqrt(dis)) / (2 * a);
    double t2 = (-b - sqrt(dis)) / (2 * a);

    // 양수 중 더 큰 값 선택 (시간은 양수임)
    double t = (t1 > 0 && t2 > 0) ? (t1 > t2 ? t1 : t2) : (t1 > 0 ? t1 : t2);

    printf("(a) 착지 시간: %.2f 초\n", t);

    // 2. 수평 거리
    double x = v0x * t;
    printf("(b) 수평 거리: %.2f m\n", x);

    // 3. 충돌 시 속도 성분
    double vx = v0x;
    double vy = v0y - g * t;
    printf("(c) 충돌 시 속도 성분:\n");
    printf("    vx: %.2f m/s\n", vx);
    printf("    vy: %.2f m/s\n", vy);

    // 속도 크기
    double v = sqrt(vx * vx + vy * vy);
    printf("    속도 크기: %.2f m/s\n", v);

    // 4. 수평선과 이루는 각도
    double theta = atan2(vy, vx) * 180.0 / PI;
    printf("(d) 수평선과 이루는 각도: %.2f 도\n", theta);

    return 0;
}
