/**
 * @file verseframe.cpp
 * @brief Implementation file for VerseFrame
 */

#include "verseframe.h"
#include <QStyle>
#include <qlogging.h>

VerseFrame::VerseFrame(QWidget* parent)
  : QFrame(parent)
{
  this->setLayout(new QVBoxLayout);
  setSelected(false);
}

void
VerseFrame::setSelected(bool selected)
{
  m_selected = selected;
  setProperty("selected", selected);
  style()->polish(this);
}
