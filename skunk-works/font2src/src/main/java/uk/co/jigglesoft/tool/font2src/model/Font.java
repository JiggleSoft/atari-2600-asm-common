package uk.co.jigglesoft.tool.font2src.model;

import uk.co.jigglesoft.tool.font2src.util.BitMapUtil;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Font
{
    final Map<String, BitMap> idToBitmap = new HashMap<>();

    final Map<String, BitMap> pathToBitmap = new HashMap<>();

    final Map<String, Glyph> idToglyph = new HashMap<>();


    public BitMap getBitMapById(final String id)
    {
        return idToBitmap.get(id);
    }

    public BitMap getBitMapByFile(final File file) throws IOException
    {
        return pathToBitmap.get(BitMap.getFilePath(file));
    }

    public BitMap addBitMap(BitMap bitMap)
    {
        idToBitmap.put(bitMap.getId(), bitMap);
        pathToBitmap.put(bitMap.getPath(), bitMap);
        return bitMap;
    }


//    final String name;
//
//    final String xxxx;
//
//    final int minX;
//
//    final int maxX;
//
//    final int minY;
//
//    final int maxY;
//
//    final Map<String, Image> images;
//
//    final Map<String, Glyph> glyphs;
public static BitMap addBitMapFromFileToFont(final Font font, final String id, final File file) throws IOException
{
    final BitMap existingBitMap = font.getBitMapByFile(file);
    if (existingBitMap == null)
    {
        return font.addBitMap(BitMapUtil.loadBitMapFromFile(id, file));
    }
    return existingBitMap;
}
}
