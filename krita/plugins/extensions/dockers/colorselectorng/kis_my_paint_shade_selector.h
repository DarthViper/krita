/*
 *  Copyright (c) 2010 Adam Celarek <kdedev at xibo dot at>
 *  Copyright (c) 2008 Martin Renold <martinxyz@gmx.ch>
 *  Copyright (c) 2009 Ilya Portnov
 *
 *  This class is based on "lib/colorchanger.hpp" from MyPaint (mypaint.intilinux.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KIS_COLSELNG_MY_PAINT_SHADE_SELECTOR_H
#define KIS_COLSELNG_MY_PAINT_SHADE_SELECTOR_H

#include "kis_color_selector_base.h"
#include <QColor>
#include <QImage>

class QTimer;

class KisMyPaintShadeSelector : public KisColorSelectorBase
{
public:
    KisMyPaintShadeSelector(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    QColor pickColorAt(int x, int y);
    KisColorSelectorBase* createPopup() const;
    void setColor(const QColor& c);

private:
    void updateSelector();
    void precalculateData();
    static const int m_size = 256;
    float m_colorH, m_colorS, m_colorV;
    struct PrecalcData {
        int h;
        int s;
        int v;
    };
    PrecalcData m_precalcData[256][256];
    void calculatePos(int x, int y);

    QImage m_pixelCache;
    const KoColorSpace* m_pixelCacheColorSpace;
    QColor m_qcolor;
    bool m_initialised;
    QTimer* m_updateTimer;
};

#endif // KIS_COLSELNG_MY_PAINT_SHADE_SELECTOR_H
