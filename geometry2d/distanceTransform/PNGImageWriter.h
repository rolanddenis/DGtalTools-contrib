/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/
/**
 * @file PNGImageWriter.h
 * @ingroup Tools
 * @author Nicolas Normand (\c Nicolas.Normand@polytech.univ-nantes.fr)
 * Université Bretagne Loire, Université de Nantes,
 * Laboratoire des Sciences du Numérique de Nantes (LS2N) UMR CNRS 6004
 *
 * @date 2012/09/28
 *
 * LUTBasedNSDistanceTransform computes the 2D translated neighborhood-sequence
 * distance transform of a binary image. It reads the input images from its
 * standard input and writes the result to its standard output.
 *
 * This file is part of the DGtal library.
 */

#include "ImageFilter.h"
#include <png.h>

/**
 * \brief A PNGImageWriter is an ImageConsumer that writes PNG images to a file.
 */
class PNGImageWriter : public ImageConsumer<GrayscalePixelType>
{
  public:
    PNGImageWriter(FILE *output, bool lineBuffered = false);

    void beginOfImage(int cols, int rows);

    void endOfImage();

    void processRow(const GrayscalePixelType *inputRow);

  protected:
    png_structp _png_ptr;
    png_infop _info_ptr;

    FILE *_output;
    bool _lineBuffered;
};
