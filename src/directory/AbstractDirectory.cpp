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
#include "../Client.h"
#include "AbstractDirectory.h"
#include "Exchanger.h"

#include "../util/bit_reverse.h"

namespace librevault {

AbstractDirectory::AbstractDirectory(Client& client, Exchanger& exchanger) :
		Loggable(client), client_(client), exchanger_(exchanger) {}
AbstractDirectory::~AbstractDirectory() {}

std::string AbstractDirectory::path_id_readable(const blob& path_id) {
	return crypto::Base32().to_string(path_id);
}

std::string AbstractDirectory::encrypted_data_hash_readable(const blob& block_id) {
	return crypto::Base32().to_string(block_id);
}

} /* namespace librevault */
