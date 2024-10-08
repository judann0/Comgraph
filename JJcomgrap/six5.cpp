#include "gl/glut.h"
#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>
#include <iostream>

// ������ ũ��
int width = 500, height = 500;

// �޽� ��ü
pmp::SurfaceMesh mesh;

// InitMyMesh �Լ� ���� (ũ�Ⱑ 2�� ������ü ����, �� ���� �� ���� �ﰢ������ ����)
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
        // ������ü�� �� ���� �� ���� �ﰢ������ ������ �߰�
        mesh.add_triangle(v0, v1, v2); // �Ʒ� �� ù ��° �ﰢ��
        mesh.add_triangle(v0, v2, v3); // �Ʒ� �� �� ��° �ﰢ��

        mesh.add_triangle(v4, v5, v6); // �� �� ù ��° �ﰢ��
        mesh.add_triangle(v4, v6, v7); // �� �� �� ��° �ﰢ��

        mesh.add_triangle(v0, v1, v5); // �� �� ù ��° �ﰢ��
        mesh.add_triangle(v0, v5, v4); // �� �� �� ��° �ﰢ��

        mesh.add_triangle(v2, v3, v7); // �� �� ù ��° �ﰢ��
        mesh.add_triangle(v2, v7, v6); // �� �� �� ��° �ﰢ��

        mesh.add_triangle(v0, v3, v7); // ���� �� ù ��° �ﰢ��
        mesh.add_triangle(v0, v7, v4); // ���� �� �� ��° �ﰢ��

        mesh.add_triangle(v1, v2, v6); // ������ �� ù ��° �ﰢ��
        mesh.add_triangle(v1, v6, v5); // ������ �� �� ��° �ﰢ��

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
