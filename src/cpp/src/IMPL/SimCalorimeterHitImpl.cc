#include "IMPL/SimCalorimeterHitImpl.h"

namespace IMPL{
  
  SimCalorimeterHitImpl::SimCalorimeterHitImpl() :
    _cellID0(0),
    _cellID1(0),
    _energy(0){
  }

// // deep copy of the SimCalorimeterHit hit
// SimCalorimeterHitImpl::SimCalorimeterHitImpl(const SimCalorimeterHit& hit) :
//   _cellID0( hit.getCellID0() ),
//   _cellID1( hit.getCellID1() ),
//   _energy( hit.getEnergy() ) {
  
//   const float* p = hit.getPosition() ;
//   _position[0] = p[0] ;
//   _position[1] = p[1] ;
//   _position[2] = p[2] ;
  
//   int nMC = hit.getNMCParticles() ;
  
//   // now copy all the MCParticle contributions
//   for(int i=0; i<nMC ;i++){
    
//     MCParticleCont* con = new  MCParticleCont ;
    
//     con->Particle = hit.getParticleCont(i) ;
//     con->Energy = hit.getEnergyCont(i) ;
//     con->Time = hit.getTimeCont(i) ;
//     con->PDG = hit.getPDGCont(i) ;
    
//     _vec.push_back( con ) ;
//   }  
// }

//EVENT::SimCalorimeterHit* SimCalorimeterHitImpl::clone() const{
  EVENT::LCObject* SimCalorimeterHitImpl::clone() const{
    // shallow copy ... more thought needed
    return new SimCalorimeterHitImpl( *this ) ;
  }
  

  SimCalorimeterHitImpl::~SimCalorimeterHitImpl(){
    // delete all MCParticle contributions
    MCParticleContVec::iterator iter = _vec.begin() ;
    
    while( iter != _vec.end() ){
      delete *iter++ ;
    }
    
  }
  
  int SimCalorimeterHitImpl::getCellID0() const {
    return _cellID0 ;
  }
  
  int SimCalorimeterHitImpl::getCellID1() const {
    return _cellID1 ;
  }
  
  float SimCalorimeterHitImpl::getEnergy() const {
    return _energy ;
  }
  
  const float* SimCalorimeterHitImpl::getPosition() const {
    return _position ;
  }
  
  int SimCalorimeterHitImpl::getNMCParticles() const {
    return _vec.size() ;
  }
  
  const EVENT::MCParticle * SimCalorimeterHitImpl::getParticleCont(int i) const {
    return _vec[i]->Particle ;
  }
  
  float SimCalorimeterHitImpl::getEnergyCont(int i) const {
    return _vec[i]->Energy ;
  }
  
  float SimCalorimeterHitImpl::getTimeCont(int i) const {
    return _vec[i]->Time ;
  }
  
  int SimCalorimeterHitImpl::getPDGCont(int i) const{
    return _vec[i]->PDG ;
  }
  
  void SimCalorimeterHitImpl::setCellID0(int id0){
    _cellID0 = id0 ;
  }
  
  void SimCalorimeterHitImpl::setCellID1(int id1){
    _cellID1 = id1 ;
  }
  
  void SimCalorimeterHitImpl::setEnergy(float en){
    _energy = en ;
  }
  
  void SimCalorimeterHitImpl::setPosition(float pos[3]){
    _position[0] = pos[0] ;
    _position[1] = pos[1] ;
    _position[2] = pos[2] ;
  }
  
  void SimCalorimeterHitImpl::addMCParticleContribution( const EVENT::MCParticle *p,
						      float en,
						      float t,
						      int pdg ){
    MCParticleCont* con = new  MCParticleCont ;

    con->Particle = p ;
    con->Energy = en ;
    con->Time = t ;
    con->PDG = pdg ;
    _vec.push_back( con ) ;
    
  }
  
}; // namespace IMPL