#pragma once

#include <QWidget>
#include <vector>
#include <memory>

class VisualEntity;
class Group;
class Selection;
class Tool;
class SelectionTool;

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    virtual ~Canvas();
    void setBackgroundColor(QColor val);
    void addVisualEntity(VisualEntity *val);
    void setActiveTool(Tool *val);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Group *m_mainGroup;
    Selection *m_selection;
    Tool *m_activeTool;
    std::unique_ptr<SelectionTool> m_selectionTool;
};

