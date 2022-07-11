#pragma once

#include <QtOpenGL>
#include <QObject>
#include <QFont>

#include "../Puyolib/frontend.h"

class FTextGL : public ppvs::ftext, public QObject
{
public:
	FTextGL(GLuint id, GLuint w, GLuint h, QObject* parent = nullptr);
	~FTextGL() override;

	void draw(float x, float y) override;

private:
	GLuint id, w, h;
};

class FFontGL : public ppvs::ffont, public QObject
{
public:
	FFontGL(const QString& fn, double fontSize, QGLWidget* gl, QObject* parent = nullptr);

	QImage renderTextline(const QString& line) const;
	ppvs::ftext* render(const char* str) override;

private:
	QGLWidget* gl;
	QFont font;
};
