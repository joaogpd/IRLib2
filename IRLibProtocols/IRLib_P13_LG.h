/* IRLib_P13_LG.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 */
/*
 * This is dummy code that you can copy and rename and modify when implementing new protocols.
 */

#ifndef IRLIB_PROTOCOL_13_H
#define IRLIB_PROTOCOL_13_H
#define IR_SEND_PROTOCOL_13		case 13: IRsendLG::send(data); break;
#define IR_DECODE_PROTOCOL_13	if(IRdecodeLG::decode()) return true;
#ifdef IRLIB_HAVE_COMBO
	#define PV_IR_DECODE_PROTOCOL_13 ,public virtual IRdecodeLG
	#define PV_IR_SEND_PROTOCOL_13   ,public virtual IRsendLG
#else
	#define PV_IR_DECODE_PROTOCOL_13  public virtual IRdecodeLG
	#define PV_IR_SEND_PROTOCOL_13    public virtual IRsendLG
#endif

#ifdef IRLIBSENDBASE_H
class IRsendLG: public virtual IRsendBase {
  public:
    void IRsendLG::send(uint32_t data) {
      sendGeneric(data, 28, 16 * 540, 8 * 540, 
        540, 540, 3 * 540, 540, 38, false);
    };
};
#endif  //IRLIBSENDBASE_H

#ifdef IRLIBDECODEBASE_H
class IRdecodeLG: public virtual IRdecodeBase {
  public:
    bool IRdecodeLG::decode(void) {
      IRLIB_ATTEMPT_MESSAGE(F("LG"));
      if (!decodeGeneric(60, 16 * 540, 8 * 540, 540, 3 * 540, 540)) {
        return false;
      }
      protocolNum = LG;
      return true;
    }
};

#endif //IRLIBDECODEBASE_H

#define IRLIB_HAVE_COMBO

#endif //IRLIB_PROTOCOL_13_H
