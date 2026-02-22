/**
 * @file verseframe.h
 * @brief Header file for VerseFrame
 */

#ifndef VERSEFRAME_H
#define VERSEFRAME_H

#include <QApplication>
#include <QFrame>
#include <QPalette>
#include <QVBoxLayout>

/**
 * @brief VerseFrame represents a custom QFrame component surrounding a Quran
 * verse.
 */
class VerseFrame : public QFrame
{
  Q_OBJECT

public:
  /**
   * @brief Class constructor
   * @param parent - pointer to parent widget
   */
  VerseFrame(QWidget* parent = nullptr);

  /**
   * @brief set the VerseFrame::m_selected member and change the stylesheet
   * accordingly.
   * @param selected - selection state
   */
  void setSelected(bool selected);

private:
  /**
   * @brief boolean value representing Frame selection state.
   */
  bool m_selected = false;
};

#endif // VERSEFRAME_H
