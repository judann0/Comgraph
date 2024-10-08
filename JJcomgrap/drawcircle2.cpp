// ���� �� ����� �ڵ� �߰�
// bool drawing = false; // �׸��� ���� Ȯ��

#include "GL/glut.h"
#include <cmath>
#include <vector>

// ȭ�� ũ��� �߽� ��ǥ
const int width = 800;
const int height = 600;
const float center_x = width / 2;
const float center_y = height / 2;

// ���� �׸��� ���� ����ü�� ����
struct circle {
    float x, y, radius;
    circle(float x, float y, float r) : x(x), y(y), radius(r) {}
};

std::vector<float> drawcircle; // ����ڰ� �׸� ��� ����
circle* correctcircle = nullptr; // ���� �� ����
bool showcircle = false;  // ���� ǥ������ ���� Ȯ��

bool drawing = false; // �׸��� ���� Ȯ��
float startx, starty;   // ���콺 ù Ŭ�� ��ǥ

// ȭ���� �׸��� �Լ�
void display() {
    glclear(gl_color_buffer_bit);

    // �߽��� c�� �׸���
    glcolor3f(0.0, 0.0, 0.0); // ������
    glpointsize(5.0);
    glbegin(gl_points);
    glvertex2f(center_x, center_y);
    glend();

    // ����ڰ� �׸� ��θ� ���
    if (!drawcircle.empty()) {
        glcolor3f(0.0, 0.0, 1.0); // �Ķ���
        glbegin(gl_line_strip);
        for (size_t i = 0; i < drawcircle.size(); i += 2) {
            glvertex2f(drawcircle[i], drawcircle[i + 1]);
        }
        glend();
    }

    // ���� ���� ��� (showcircle�� true�� ���� �׸���)
    if (showcircle && correctcircle) {
        glcolor3f(1.0, 0.0, 0.0); // ������
        glbegin(gl_line_loop);
        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180.0;
            float x = correctcircle->x + cos(angle) * correctcircle->radius;
            float y = correctcircle->y + sin(angle) * correctcircle->radius;
            glvertex2f(x, y);
        }
        glend();
    }

    glutswapbuffers();
}

// ���콺 Ŭ�� �� ȣ��Ǵ� �Լ�
void mouse(int button, int state, int x, int y) {
    y = height - y; // ��ǥ�踦 opengl ��ǥ�� ��ȯ

    if (button == glut_left_button) {
        if (state == glut_down && !drawing) {
            // ù Ŭ�� �� ���� ��ǥ ����
            startx = x;
            starty = y;
            drawing = true;
            drawcircle.clear();
            showcircle = false;  // ���ο� ������� ���۵Ǹ� ���� ����
        }
        else if (state == glut_up && drawing) {
            // �׸��� ���� �� ���� ���� ���
            drawing = false;
            float radius = sqrt(pow(startx - center_x, 2) + pow(starty - center_y, 2));
            correctcircle = new circle(center_x, center_y, radius);
            showcircle = true;  // ���� �׸����� ����
            glutpostredisplay(); // ȭ�� ����
        }
    }
}

// ���콺 �̵� �� ȣ��Ǵ� �Լ�
void motion(int x, int y) {
    if (drawing) {
        y = height - y; // ��ǥ�踦 opengl ��ǥ�� ��ȯ
        drawcircle.push_back(x);
        drawcircle.push_back(y);
        glutpostredisplay(); // ȭ�� ����
    }
}

// ȭ�� ũ�� ���� �� ȣ��Ǵ� �Լ�
void reshape(int w, int h) {
    glviewport(0, 0, w, h);
    glmatrixmode(gl_projection);
    glloadidentity();
    gluortho2d(0.0, w, 0.0, h);
    glmatrixmode(gl_modelview);
}

// ���� �Լ�
int main(int argc, char** argv) {
    glutinit(&argc, argv);
    glutinitdisplaymode(glut_double | glut_rgb);
    glutinitwindowsize(width, height);
    glutcreatewindow("�� �׸��� ����");

    glclearcolor(1.0, 1.0, 1.0, 1.0); // ��� ���� ����
    glutdisplayfunc(display);  // ���÷��� �Լ� ���
    glutreshapefunc(reshape);  // ������ ũ�� ���� �Լ� ���
    glutmousefunc(mouse);      // ���콺 Ŭ�� �Լ� ���
    glutmotionfunc(motion);    // ���콺 �̵� �Լ� ���

    glutmainloop(); // ���� ���� ����
    return 0;
}
