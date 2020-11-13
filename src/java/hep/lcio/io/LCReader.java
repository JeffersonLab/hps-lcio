// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================

package hep.lcio.io;

import hep.lcio.event.LCEvent;
import hep.lcio.event.LCRunHeader;
import java.io.IOException;

/**Interface for reading data from LCIO.
 * Use LCFactory to instantiate a corresponding LCWriter object
 * for the output format at hand (SIO only, so far).
 *
 * @see LCFactory
 * 
 * @author gaede
 * @version Mar 4, 2003
 */
public interface LCReader {

    /** Opens a file for reading (read-only).
     *
     * @throws IOException
     */
    public void open(String filename) throws IOException;

    /** Opens a list of files for reading (read-only). All subsequent
     * read operations will operate on the list, i.e. if an EOF is encountered
     * the next file in the list will be opened and read transparently to the
     * user.
     *
     * @throws IOException
     */
    public void open(String[] filenames) throws IOException;

    /** Reads the next run header from the file. Returns NULL if
     * 'EOF' read. 
     *
     * @throws IOException
     */
    public LCRunHeader readNextRunHeader() throws IOException;

    /** Same as readNextRunHeader() but allows to set the access mode 
     *  LCIO::READ_ONLY (default) or LCIO::Update. 
     *
     * @throws IOException
     */
    public LCRunHeader readNextRunHeader(int accessMode) throws IOException;

    /** Reads the next event from the file. Returns NULL if
     * 'EOF' read. 
     *
     * @throws IOException
     */
    public LCEvent readNextEvent() throws IOException;

    /** Same as readNextEvent() but allows to set the access mode 
     *  LCIO::READ_ONLY (default) or LCIO::Update. 
     *
     * @throws IOException
     */
    public LCEvent readNextEvent(int accessMode) throws IOException;

  /** Skips the next n events from the current position.
     * @throws IOException
     */
    public void skipNEvents(int n) throws IOException;

    /** Reads the specified runHeader from file. Returns NULL if
     *  the specified runHeader hasn't been found in the file.
     *
     * @throws IOException
     */
    public LCRunHeader readRunHeader(int runNumber) throws IOException;

    /** Same as LCEvent* readRunHeader(int runNumber) 
     *  allowing to set the access mode LCIO::READ_ONLY (default) or LCIO::Update.
     *
     * @throws IOException
     */
    public LCRunHeader readRunHeader(int runNumber, int accessMode) throws IOException;

    /** Reads the specified event from file. Returns NULL if
     *  the specified event hasn't been found in the file.
     *
     * @throws IOException
     */
    public LCEvent readEvent(int runNumber, int evtNumber) throws IOException;

    /** Same as LCEvent* readEvent(int runNumber, int evtNumber) 
     *  allowing to set the access mode LCIO::READ_ONLY (default) or LCIO::Update.
     *
     * @throws IOException
     */
    public LCEvent readEvent(int runNumber, int evtNumber, int accessMode) throws IOException;

    /** Closes the output file/stream etc.
     *
     * @throws IOException
     */
    public void close() throws IOException;

    /** Registers a listener for reading LCEvents from a stream.
     */ 
    public void registerLCEventListener(LCEventListener ls);

    /** Remove a listener for reading LCEvents from a stream.
     */ 
    public void removeLCEventListener(LCEventListener ls);

    /** Registers a listener for reading LCEventsLCRunHeaders from a stream.
     */ 
    public void registerLCRunListener(LCRunListener ls);

    /** Remove a listener for reading LCRunHeaders from a stream.
     */ 
    public void removeLCRunListener(LCRunListener ls);

    /** Reads the input stream and notifies registered 
     * listeners according to the object type 
     * found in the stream. 
     *
     * @throws IOException
     */
    public void readStream() throws IOException;

    /** Reads maxRecord from the input stream and notifies registered 
     * listeners according to the object type found in the stream.
     * An exception is thrown if less than maxRecord where read from the file.
     *
     * @throws IOException
     */
    public void readStream(int maxRecord) throws IOException;

    /** Configuration flags for the LCReader instance - to be used with LCFactory::createLCReader(). */
          
     
                                                       
      
    public final static int directAccess = 0x00000001;
} // class or interface
