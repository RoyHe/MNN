# automatically generated by the FlatBuffers compiler, do not modify

# namespace: MNN

import flatbuffers

class CastParam(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsCastParam(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = CastParam()
        x.Init(buf, n + offset)
        return x

    # CastParam
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # CastParam
    def SrcT(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # CastParam
    def DstT(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

def CastParamStart(builder): builder.StartObject(2)
def CastParamAddSrcT(builder, srcT): builder.PrependInt32Slot(0, srcT, 0)
def CastParamAddDstT(builder, dstT): builder.PrependInt32Slot(1, dstT, 0)
def CastParamEnd(builder): return builder.EndObject()
