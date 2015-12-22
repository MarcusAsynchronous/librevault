/* Copyright (C) 2015 Alexander Shishenko <GamePad64@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "../pch.h"
#pragma once
#include "Meta.h"
#include "AbstractDirectory.h"

namespace librevault {

class RemoteDirectory : public AbstractDirectory {
public:
	RemoteDirectory(Client& client, Exchanger& exchanger);
	virtual ~RemoteDirectory();

	// Choking
	virtual void choke() = 0;
	virtual void unchoke() = 0;
	virtual void interest() = 0;
	virtual void uninterest() = 0;

	virtual void post_have_meta(const Meta::PathRevision& revision, const bitfield_type& bitfield) = 0;
	virtual void post_have_block(const blob& encrypted_data_hash) = 0;

	virtual void request_meta(const Meta::PathRevision& revision) = 0;
	virtual void post_meta(const Meta::SignedMeta& smeta, const bitfield_type& bitfield) = 0;
	virtual void cancel_meta(const Meta::PathRevision& revision) = 0;

	virtual void request_chunk(const blob& encrypted_data_hash, uint32_t offset, uint32_t size) = 0;
	virtual void post_chunk(const blob& encrypted_data_hash, uint32_t offset, const blob& chunk) = 0;
	virtual void cancel_chunk(const blob& encrypted_data_hash, uint32_t offset, uint32_t size) = 0;

	bool am_choking() const {return am_choking_;}
	bool am_interested() const {return am_interested_;}
	bool peer_choking() const {return peer_choking_;}
	bool peer_interested() const {return peer_interested_;}

protected:
	Client& client_;
	Exchanger& exchanger_;

	bool am_choking_ = true;
	bool am_interested_ = false;
	bool peer_choking_ = true;
	bool peer_interested_ = false;
};

} /* namespace librevault */
