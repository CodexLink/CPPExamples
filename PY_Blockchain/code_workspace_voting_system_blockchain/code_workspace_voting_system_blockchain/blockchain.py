from datetime import datetime
import json
import hashlib
import calendar


class Blockchain:
    def __init__(self, current_node_url):
        self.obj = {
            "chain": [],
            "pending_bets": [],
            "network_nodes": [],
            "current_node_url": current_node_url,
        }
        # Genesis block
        print(self.create_new_block(100, "0", "0"))

    def get_blockchain(self):
        return json.dumps(self.obj)

    def create_new_block(self, nonce, previous_hash, block_hash):
        d = datetime.utcnow()
        _obj = self.obj
        block = {
            "index": len(_obj["chain"]) + 1,
            "timestamp": calendar.timegm(d.utctimetuple()),
            "bets": _obj["pending_bets"],
            "nonce": nonce,
            "hash": block_hash,
            "previous_block_hash": previous_hash,
        }

        _obj["pending_bets"] = []
        _obj["chain"].append(block)

        return block
