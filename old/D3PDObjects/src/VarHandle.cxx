// $Id: CodeGenerator_v2_constants.h 445228 2011-06-24 09:29:49Z krasznaa $

// Local include(s):
#include "../include/VarHandle.h"

namespace D3PDReader {

   VarHandleBase::VarHandleBase( ::TObject* parent, const char* name,
                                 const ::Long64_t* master )
      : fMaster( master ), fParent( parent ), fFromInput( kFALSE ),
        fInTree( 0 ), fInBranch( 0 ), fAvailable( UNKNOWN ), fName( name ),
        fActive( kFALSE ) {

   }

   const char* VarHandleBase::GetName() const {

      return fName;
   }

   void VarHandleBase::SetName( const char* name ) {

      fName = name;
      return;
   }

   ::Bool_t VarHandleBase::IsActive() const {

      return fActive;
   }

   void VarHandleBase::SetActive( ::Bool_t active ) {

      fActive = active;
      return;
   }

} // namespace D3PDReader
