package uk.co.jigglesoft.tool.font2src.util;

import uk.co.jigglesoft.tool.font2src.model.BitMap;
import uk.co.jigglesoft.tool.font2src.model.Font;

import javax.imageio.ImageIO;
import java.awt.Image;
import java.io.File;
import java.io.IOException;

public class BitMapUtil
{
    public static BitMap loadBitMapFromFile(final String id, final File file) throws IOException
    {
        Image        image  = ImageIO.read(file);
        final BitMap bitMap = new BitMap(id, file, image);
        return bitMap;
    }



}
