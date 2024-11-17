


#_______________________________________________________________________
# METHOD GATE-FUNCTIONS ################################################
#
#_______________________________________________
#
#	- five basic methods implemented:
#
#		- _::class			define new class
#
#		- _::new			create new object of the class
#
#		- _::del			delete object
#
#		- _::dup			duplicate objects
#
#
#
#_______________________________________________________________________
########################################################################

@namespace "class"

#_______________________________________________________________________
########################################################################

func	method::class()	{ return "		name		, parentptr, psfx, D " }
func	method::new() 	{ return "**	class		, ptr			   " }
func	method::del() 	{ return "**	ptr					   " }
func	method::dup() 	{ return "+		ptr					   " }
func	method::w()	  	{ return "		ptr		, data		   " }
func	method::r()	  	{ return "**	ptr					   " }

#_________________________________________________________________
func	_::class( n, pp, psx, D ,cm,pm,x ) { #######################

	if ( ! init0_f )

		init0()
	#_____________________________
	#
	# define new class `n
	#
	#	with parent `pp
	#	prefix/suffix determinated by `psx
	#_____________________________

	x = API_

	if ( pp in PARENTPTR )

		pp = PARENTPTR[ pp ]

	if ( pp in CLASS ) {

		cm = n METHODSEP_ "class"

		pm = pp METHODSEP_ "class"

		if ( cm in FUNC::TAB ) {

			API_ = FUNC::TAB[ cm ]

			if ( pm in FUNC::TAB )

				if ( API_ != FUNC::TAB[ pm ] )

					_APITAB[ API_ ] = FUNC::TAB[ pm ] }

		else

			if ( pm in FUNC::TAB )

				API_ = FUNC::TAB[ pm ]

			else

				API_ = null

		if ( API_ ) {

			n = @API_( n, pp, psx, D )

			API_ = x

			return n }

		else

			return class_err( "@2: def method missed", n, pp ) }

	else

		return class_err( "undefined parentptr: @2", n, pp ) }

	#_______________________

	func	class_err( t, p1,p2,p3,p4 ) {

		return error( "_::class( @1, " t " )", p1,p2,p3,p4 ) }

#_________________________________________________________________
func	_::new( p, p2,p3,p4,p5,p6,p7,p8 ) { ########################

	# create new ptr of class `p
	#
	#_____________________________

	if ( isnull( p ) )

		return new_err( "parentptr not specified" )

	if ( p in PARENTPTR )

		p = PARENTPTR[ p ]

	return _::api( "new", p, p2,p3,p4,p5,p6,p7,p8 ) }

	#_____________________________

	func	new_err( t, p1,p2,p3,p4 ) {

		return error( "_::new( " t " )", p1,p2,p3,p4 ) } 

#___________________________________________________________
func	_::del( p, p2,p3,p4,p5,p6,p7,p8 ) { ##################

	# delete `p
	#
	#_____________________________

	return _::api( "del", p, p2,p3,p4,p5,p6,p7,p8 ) }

#___________________________________________________________
func	_::dup( p, p2,p3,p4,p5,p6,p7,p8 ) { ##################

	# duplicate `p
	#_____________________________

	return _::api( "dup", p, p2,p3,p4,p5,p6,p7,p8 ) }

#___________________________________________________________
func	_::w( p, p2,p3,p4,p5,p6,p7,p8 ) { ####################

	# write `t to `p
	#_____________________________

	if ( isnull( p ) )

		return w_err( "no pointer" )

	if ( p in PARENTPTR )

		p = PARENTPTR[ p ]

	if ( p in CLASS )

		p = _::new( p )

	else	if ( ! ( p in PARENT ) )

			return w_err( "bad pointer: @1", p )

	return _::api( "w", p, p2,p3,p4,p5,p6,p7,p8 ) }
	#_____________________________

	func	w_err( t, p1,p2,p3,p4 ) {

		return error( "_::w( " t " )", p1,p2,p3,p4 ) }

#___________________________________________________________
func	_::r( p, p2,p3,p4,p5,p6,p7,p8 ) { ###############################

	return _::api( "r", p, p2,p3,p4,p5,p6,p7,p8 ) }

#_______________________________________________________________________
########################################################################


	