// -*- C++ -*-
#ifndef IMPL_VERTEXIMPL_H
#define IMPL_VERTEXIMPL_H 1


#include "EVENT/Vertex.h"
#include "AccessChecked.h"

#define VTXCOVMATRIX 6


namespace IMPL {


/** Implementation of Vertex Class.
 *
 * @see Vertex
 * @author gaede, engels
 * @version Aug 09, 2006
 */
  class VertexImpl : public EVENT::Vertex, public AccessChecked {
  
	  
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    VertexImpl() ;
    
    // Destructor.
    virtual ~VertexImpl() = default;

    VertexImpl(const VertexImpl&) = default;

    VertexImpl& operator=(const VertexImpl&) = default; 

    virtual int id() const { return simpleUID() ; }
    
    /** Checks if the Vertex is the primary vertex of the event.
     *  Only one primary vertex per event is allowed
     */
    virtual bool isPrimary() const ;
     
    /** Type code for the algorithm that has been used to create the vertex - check/set the
     *  collection parameters AlgorithmName and  AlgorithmType.
     */
    //virtual int getAlgorithmType() const ;
    virtual const std::string& getAlgorithmType() const ;

    /** Chi squared of the vertex fit.
     */
    virtual float getChi2() const;
                                                                                                         
    /** Probability of the vertex fit.
     */
    virtual float getProbability() const;
                                                                                                         
    /** Position of the vertex 
     */
    virtual const float* getPosition() const;
                                                                                                         
    /** Covariance matrix of the position (stored as lower triangle matrix, i.e.
     *  cov(xx),cov(y,x),cov(y,y) ).
     */
    virtual const EVENT::FloatVec & getCovMatrix() const;

    /** Additional parameters related to this vertex - check/set the collection
     *  parameter "VertexParameterNames" for the parameters' meaning.
     */
    virtual const EVENT::FloatVec & getParameters() const;

    /** Returns Reconstructed Particle associated to the Vertex
     */
    virtual EVENT::ReconstructedParticle * getAssociatedParticle() const;

    // setters
    void setPrimary( bool primary ) ;
    //void setAlgorithmType( int type ) ;
    void setAlgorithmType( std::string type ) ;
    void setChi2( float chi2 ) ;
    void setProbability( float probability ) ;
    void setPosition( const float vpos[3] ) ;
    void setPosition( float px, float py, float pz ) ;
    void setCovMatrix( const float* cov ) ;
    void setCovMatrix( const EVENT::FloatVec & ) ;
    void setAssociatedParticle( EVENT::ReconstructedParticle * aP ) ;
    void addParameter( float p );

  protected:
    int _primary{0} ;
    //int _type ;
    std::string _type{"Unknown"} ;
    float _chi2{0.} ;
    float _probability{0.} ;
    float _vpos[3] = {0., 0., 0.} ;
    EVENT::FloatVec _cov{} ;
    EVENT::FloatVec _par{} ;
    EVENT::ReconstructedParticle* _aParticle{nullptr} ;
   
}; // class

} // namespace IMPL
#endif /* ifndef IMPL_VERTEXIMLP_H */
