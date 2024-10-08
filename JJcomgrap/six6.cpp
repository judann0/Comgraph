#include "gl/glut.h"
#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>
#include <iostream>

// ������ ũ��
int width = 500, height = 500;

// �޽� ��ü
pmp::SurfaceMesh mesh;

// InitMyMesh �Լ� ���� (ũ�Ⱑ 2�� ������ü ����, �� ���� �簢������ �߰�)
void InitMyMesh() {
    // ������ü ������ �߰�
    auto v0 = mesh.add_vertex(pmp::Point(-1, -1, -1));
    auto v1 = mesh.add_vertex(pmp::Point(1, -1, -1));
    auto v2 = mesh.add_vertex(pmp::Point(1, 1, -1));
    auto v3 = mesh.add_vertex(pmp::Point(-1, 1, -1));
    auto v4 = mesh.add_vertex(pmp::Point(-1, -1, 1));
    auto v5 = mesh.add_vertex(pmp::Point(1, -1, 1));
    auto v6 = mesh.add_vertex(pmp::Point(1, 1, 1));
    auto v7 = mesh.add_vertex(pmp::Point(-1, 1, 1));

    try {
        // ������ü�� �� ���� �簢������ �߰�
        mesh.add_quad(v0, v1, v2, v3); // �Ʒ� ��
        mesh.add_quad(v4, v5, v6, v7); // �� ��
        mesh.add_quad(v0, v1, v5, v4); // �� ��
        mesh.add_quad(v2, v3, v7, v6); // �� ��
        mesh.add_quad(v0, v3, v7, v4); // ���� ��
        mesh.add_quad(v1, v2, v6, v5); // ������ ��

        // �޽��� ���Ϸ� ���� (output.obj)
        pmp::write(mesh, "output.obj");
        std::cout << "OBJ ������ 'output.obj'�� ����Ǿ����ϴ�.\n";
    }
    catch (const pmp::TopologyException& e) {
        std::cerr << "TopologyException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "���� �߻�: " << e.what() << std::endl;
    }
}

// ���÷��� �ݹ� �Լ�
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();
    glutSwapBuffers();
}

// ������ ũ�� ���� �ݹ� �Լ�
void reshape(int w, int h) {
    if (h == 0)
        h = 1;
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
}

// ���� �Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Cube OBJ Export");

    // InitMyMesh() �Լ� ȣ���Ͽ� ������ü ���� �� OBJ ���Ϸ� ����
    InitMyMesh();

    // GLUT �ݹ� �Լ� ���
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // GLUT ���� ���� ����
    glutMainLoop();

    return 0;
}
