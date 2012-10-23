// Dear emacs, this is -*- c++ -*-
// $Id: CodeGenerator_v2_constants.h 445228 2011-06-24 09:29:49Z krasznaa $
#ifndef D3PDREADER_VARPROXY_H
#define D3PDREADER_VARPROXY_H

// STL include(s):
#include <vector>

// Local include(s):
#include "VarHandle.h"

// Forward declaration(s):
class TObject;

namespace D3PDReader {

   /**
    *  @short Class acting as a proxy to one element of an std::vector
    *
    *         This class is used in the "Element" classes to represent one
    *         object from a collection.
    *
    * @author Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
    *
    * $Revision: 445228 $
    * $Date: 2011-06-24 11:29:49 +0200 (Fri, 24 Jun 2011) $
    */
   template< typename Type >
   class VarProxy {

   public:
      /// Convenience typedef of the used variable
      typedef Type& result_type;
      /// Convenience typedef of the used variable (const version)
      typedef const Type& const_result_type;

      /// Constructor specifying the handle object this proxy uses
      VarProxy( const VarHandle< std::vector< Type >* >& handle, size_t i,
                ::TObject* parent );
      /// Copy constructor
      VarProxy( const VarProxy< Type >& parent );
      /// Copy operator
      VarProxy< Type >& operator=( const VarProxy< Type >& parent );

      /// Check if the variable is available in the input
      ::Bool_t IsAvailable() const;

      /// Operator returning the variable belonging to this object
      result_type operator()();
      /// Operator returning the variable belonging to this object (constant version)
      const_result_type operator()() const;

   private:
      VarHandle< std::vector< Type >* >* fHandle; ///< Pointer to the handle object
      size_t fIndex; ///< Index inside the handle object's vector
      ::TObject* fParent; ///< Pointer to the parent object
      Type fDummy; ///< Object returned by default

   }; // class VarProxy

} // namespace D3PDReader

// Include the implementation:
#ifndef __CINT__
#include "VarProxy.icc"
#endif // __CINT__

#endif // D3PDREADER_VARPROXY_H
